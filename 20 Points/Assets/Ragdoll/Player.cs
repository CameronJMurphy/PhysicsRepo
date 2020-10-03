using System.Collections;
using System.Collections.Generic;
using System.Net;
using UnityEngine;
[RequireComponent(typeof(CharacterController))]
[RequireComponent(typeof(Animator))]

public class Player : MonoBehaviour
{
	CharacterController controller = null;
	Animator animator = null;
	public float speed = 240.0f;
	public float pushPower = 2.0f;
	CarController car;
	MoveToCar moveToCar;

	// Use this for initialization
	void Start()
	{
		controller = GetComponent<CharacterController>();
		animator = GetComponent<Animator>();
		car = FindObjectOfType<CarController>();
		moveToCar = FindObjectOfType<MoveToCar>();
	}
	// Update is called once per frame
	void Update()
	{
		float vertical = Input.GetAxis("Vertical");
		float horizontal = Input.GetAxis("Horizontal");
		controller.SimpleMove(transform.up * Time.deltaTime);
		transform.Rotate(transform.up, horizontal * speed /4 * Time.deltaTime);
		animator.SetFloat("Speed", vertical * speed * Time.deltaTime);
	}
	void OnControllerColliderHit(ControllerColliderHit hit)
	{
		Rigidbody body = hit.collider.attachedRigidbody;
		if (body == null || body.isKinematic)
			return;
		if (hit.moveDirection.y < -0.3F)
			return;
		Vector3 pushDir = new Vector3(hit.moveDirection.x, 0, hit.moveDirection.z);
		body.velocity = pushDir * pushPower;

		if(hit.gameObject.tag == "Car")
		{
			car.ManVechicle();
			moveToCar.Invoke();
			Destroy(gameObject);
		}
	}
}