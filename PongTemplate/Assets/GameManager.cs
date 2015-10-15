using UnityEngine;
using System.Collections;

public class GameManager : MonoBehaviour
{
	public ScoreManager scoreManager;
	public Paddle leftPaddle;
	public Paddle rightPaddle;
	public Ball ball;
	private bool isStarted = false;
	private bool isPaused = false;

	void Update()
	{
		if (Input.GetKeyDown(KeyCode.Space))
		{
			if (!isStarted)
				Play();
			else
				TogglePause();
		}

		if (Input.GetKeyDown(KeyCode.R))
			Reset();
	}

	public void TogglePause()
	{
		if (isPaused)
			Time.timeScale = 1;	// Play
		else
			Time.timeScale = 0;	// Pause

		isPaused = !isPaused;
	}

	public IEnumerator HasWon()
	{
		ball.ResetVelocity();
		
		yield return new WaitForSeconds(3.0f);
		
		Reset();
	}

	void Reset()
	{
		scoreManager.Reset();

		leftPaddle.Reset();
		rightPaddle.Reset();

		ball.ResetPosition();
		ball.ResetVelocity();

		isStarted = false;
		isPaused = false;

		Time.timeScale = 1;
	}

	void Play()
	{
		ball.Launch();

		isStarted = true;
		isPaused = false;
	}
}
