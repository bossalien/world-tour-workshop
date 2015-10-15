using UnityEngine;
using System.Collections;

public abstract class Paddle : MonoBehaviour
{
	public void Reset()
	{
		if (transform.name == "LeftPaddle")
			transform.position = new Vector2(-21f, 0);
		else
			transform.position = new Vector2(21f, 0);
	}

	public virtual void OnNotifyBallBounced() { }
}
