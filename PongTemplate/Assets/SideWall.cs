using UnityEngine;
using System.Collections;

public class SideWall : Wall
{
	public ScoreManager scoreManager;
	
	public override void OnCollisionEnter2D(Collision2D hitInfo)
	{
		if (hitInfo.transform.name == "Ball")
			scoreManager.AssignPoint(transform.name);

		base.OnCollisionEnter2D(hitInfo);
	}
}
