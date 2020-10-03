using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpeedBoost : MonoBehaviour
{
	Vector3 amount = new Vector3(0, 0, 1000);
	private void OnTriggerEnter(Collider other)
	{
		other.gameObject.GetComponent<Rigidbody>().AddRelativeForce(amount);
	}
}
