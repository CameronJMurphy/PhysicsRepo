using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnFlipCar : MonoBehaviour
{

    // Update is called once per frame
    void Update()

    {
        if (Input.GetKey(KeyCode.Z))
        {
            gameObject.GetComponent<Rigidbody>().isKinematic = true;
			//Lift them into the air
			Vector3 inAir = new Vector3(gameObject.transform.position.x, 1.649f, gameObject.transform.position.z);
			gameObject.transform.position = Vector3.Lerp(gameObject.transform.position, inAir, 0.1f);

			//flip it around
			Quaternion upright = new Quaternion(0, gameObject.transform.rotation.y, 0, gameObject.transform.rotation.w);
            gameObject.transform.rotation = Quaternion.Lerp(gameObject.transform.rotation, upright , 0.1f);

            
        }
        if(Input.GetKeyUp(KeyCode.Z))
		{
            gameObject.GetComponent<Rigidbody>().isKinematic = false;

        }
       


    }
}
