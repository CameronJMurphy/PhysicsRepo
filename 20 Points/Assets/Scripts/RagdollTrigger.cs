using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RagdollTrigger : MonoBehaviour
{	
	private void OnCollisionEnter(Collision collision)
	{
		Ragdoll ragdoll = collision.gameObject.GetComponentInParent<Ragdoll>();
		if (ragdoll != null)
		{
			if(ragdoll.RagdollOn != true)
			{
				ragdoll.RagdollOn = true;
				Target target = collision.gameObject.GetComponentInParent<Target>();
				if (target != null)
				{
					GameCon.instance.AddPoints(target.pointValue);
				}
			}
		}
		
	}

}
