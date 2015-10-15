using UnityEngine;
using System.Collections;

public class Wall : MonoBehaviour
{
	public Paddle leftPaddle;
	public Paddle rightPaddle;

	public virtual void OnCollisionEnter2D(Collision2D col)
	{
		if (col.transform.name == "Ball")
		{
			if (transform.name == "LeftWall")
				rightPaddle.OnNotifyBallBounced();
			else if (transform.name == "RightWall")
				leftPaddle.OnNotifyBallBounced();
			else
			{
				leftPaddle.OnNotifyBallBounced();
				rightPaddle.OnNotifyBallBounced();
			}
		}
	}
}
