using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class CarController : MonoBehaviour
{
    public HingeJoint fLeft;
    public HingeJoint fRight;
    public HingeJoint bLeft;
    public HingeJoint bRight;

    //public HingeJoint UpFLeft;
    //public HingeJoint UpFRight;
    //public HingeJoint UpBLeft;
    //public HingeJoint UpBRight;

    public float speed;
    bool occupied = false;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (occupied)
        {
            float vertical = Input.GetAxis("Vertical");
            float horizontal = Input.GetAxis("Horizontal");

            Steering(vertical, -horizontal, fRight);
            Steering(vertical, -horizontal, bRight);
            Steering(vertical, horizontal, fLeft);
            Steering(vertical, horizontal, bLeft);
        }
    }

    void Steering(float vertical, float horizontal, HingeJoint hinge)
	{
        if (horizontal != 0)
        {
            var tempMotor = hinge.motor;
            tempMotor.targetVelocity = speed * vertical * horizontal;
            hinge.motor = tempMotor;
        }
		else
		{
            var tempMotor = hinge.motor;
            tempMotor.targetVelocity = speed * vertical;
            hinge.motor = tempMotor;
        }
    }

    public void ManVechicle()
	{
        occupied = true;

	}
}
