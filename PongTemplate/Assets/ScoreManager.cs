using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ScoreManager : MonoBehaviour
{
	private int player1Score;
	private int player2Score;

	public int winningScore = 10;
	public Text player1ScoreText;
	public Text player2ScoreText;

	public GameManager gameManager;

	public void Start()
	{
		ResetScore();
	}

	public void AssignPoint(string wallHitName)
	{
		if (wallHitName == "RightWall")
			player1Score++;
		else
			player2Score++;

		UpdateScoreText();
	}

	public void Reset()
	{
		ResetScore();
	}

	public int Player1Score { get { return player1Score; } }

	public int Player2Score { get { return player2Score; } }

	void ResetScore()
	{
		player1Score = 0;
		player2Score = 0;

		player1ScoreText.color = Color.white;
		player2ScoreText.color = Color.white;

		UpdateScoreText();
	}

	void UpdateScoreText()
	{
		// Check winning condition
		if (player1Score >= winningScore)
			HasWon(player1ScoreText);	// Player 1 has won
		else if (player2Score >= winningScore)
			HasWon(player2ScoreText);	// Player 2 has won
		else
		{
			player1ScoreText.text = player1Score.ToString();
			player2ScoreText.text = player2Score.ToString();
		}
	}

	void HasWon(Text winningScoreText)
	{
		winningScoreText.color = Color.green;
		winningScoreText.text = "WIN!";

		StartCoroutine(gameManager.HasWon());
	}
}
