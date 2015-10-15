using UnityEngine;
using System.Collections;

public class AIPaddle : Paddle
{
	public Ball ball;
	public float speed = 30;
	public float minBallPositionOffset = -15f;
	public float maxBallPositionOffset = 15f;
	public float minSpeedOffset = -20f;
	public float maxSpeedOffset = 0f;
	public float baseResponseDelayMs = 250f;
	public float minResponseDelayMsOffset = 0f;
	public float maxResponseDelayMsOffset = 100f;
	public float epsilon = 0.001f;

	private Vector3 move = Vector3.zero;
	private float currentBallPositionOffset;
	private float currentSpeedOffset;
	private float responseDelayTimer;
	private bool shouldTrackBall;

	protected virtual void FixedUpdate()
	{
		// Simulate delayed response time
		responseDelayTimer = Mathf.Min(0.0f, responseDelayTimer - Time.deltaTime);
		if (responseDelayTimer > 0.0f)
			return;

		float adjustedBallY = ball.transform.position.y;
		float adjustedSpeed = speed;
		
		// Avoid flickering
		if (adjustedBallY - transform.position.y >= epsilon)
		{
			// Simulate imperfect ball tracking
			adjustedBallY += currentBallPositionOffset;
			adjustedSpeed += currentSpeedOffset;
		}
		
		float yDistance = adjustedBallY - transform.position.y;
		float xDistance = ball.transform.position.x - transform.position.x;

		// Don't track ball when it's between paddle and wall or is travelling away
		if (xDistance < 0 || shouldTrackBall)
		{
			if (yDistance > 0)
			{
				move.y = adjustedSpeed * Mathf.Min(yDistance, 1.0f);
			}
			
			if (yDistance < 0)
			{
				move.y = -(adjustedSpeed * Mathf.Min(-yDistance, 1.0f));
			}
		}

		transform.position += move * Time.deltaTime;
	}

	public override void OnNotifyBallBounced()
	{
 		currentBallPositionOffset = Random.Range(minBallPositionOffset, maxBallPositionOffset);
		currentSpeedOffset = Random.Range(minSpeedOffset, maxSpeedOffset);
		responseDelayTimer = (baseResponseDelayMs + Random.Range(minResponseDelayMsOffset, maxResponseDelayMsOffset)) / 1000.0f;

		shouldTrackBall = true;
	}

	void OnCollisionExit2D(Collision2D col)
	{
		if (col.transform.name == "Ball")
			shouldTrackBall = false;
	}
}
