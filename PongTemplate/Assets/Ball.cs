using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour
{
	// TODO: Make ball go faster if score increases
	public float speed = 30;
	public TrailRenderer trail;
	public Paddle leftPaddle;
	public Paddle rightPaddle;
	
	private float lastSavedTrailTime;

	public void Start()
	{
		ResetPosition();
		ResetVelocity();
	}

	public void ResetPosition()
	{
		// Reset ball position
		transform.position = Vector2.zero;
	}

	public void ResetVelocity()
	{
		// Reset velocity
		GetComponent<Rigidbody2D>().velocity = Vector2.zero;
	}

	public void Launch()
	{
		StartCoroutine(Go());
	}

	IEnumerator Go()
	{
		yield return new WaitForSeconds(0.5f);
		
		// Initialise random velocity
		Vector2 randomDirection = new Vector2(Random.Range(-1, 1f), Random.Range(-0.5f, 0.5f));
		GetComponent<Rigidbody2D>().velocity = randomDirection.normalized * speed;
	}
    
	float hitFactor(Vector2 ballPos, Vector2 racketPos, float racketHeight)
	{
		// ascii art:
		// ||  1 <- at the top of the racket
		// ||
		// ||  0 <- at the middle of the racket
		// ||
		// || -1 <- at the bottom of the racket
		return (ballPos.y - racketPos.y) / racketHeight;
	}

	void OnCollisionEnter2D(Collision2D col)
	{
		// Hit the left Racket?
		if (col.transform.name == "LeftPaddle")
		{
			// Calculate hit Factor
			float y = hitFactor(transform.position,
                                col.transform.position,
                                col.collider.bounds.size.y);

			// Calculate direction, make length=1 via .normalized
			Vector2 dir = new Vector2(1, y).normalized;

			// Set Velocity with dir * speed
			GetComponent<Rigidbody2D>().velocity = dir * speed;

			rightPaddle.OnNotifyBallBounced();
		}

		// Hit the right Racket?
		if (col.transform.name == "RightPaddle")
		{
			// Calculate hit Factor
			float y = hitFactor(transform.position,
                                col.transform.position,
                                col.collider.bounds.size.y);

			// Calculate direction, make length=1 via .normalized
			Vector2 dir = new Vector2(-1, y).normalized;
            
			// Set Velocity with dir * speed
			GetComponent<Rigidbody2D>().velocity = dir * speed;

			leftPaddle.OnNotifyBallBounced();
		}
	}
}
