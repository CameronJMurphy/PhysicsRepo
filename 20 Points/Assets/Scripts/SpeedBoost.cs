using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpeedBoost : MonoBehaviour
{
	public Vector3 amount = new Vector3(0, 0, 1000);
	private void OnTriggerEnter(Collider other)
	{
		Rigidbody rb = other.gameObject.GetComponent<Rigidbody>();
		if (rb)
		{
			rb.AddRelativeForce(amount);
		}
	}
}
