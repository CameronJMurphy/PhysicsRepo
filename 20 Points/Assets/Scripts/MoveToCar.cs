using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveToCar : MonoBehaviour
{
    CarController car;
    Transform cameraNewPos;
    
    public void Invoke()
	{
        car = FindObjectOfType<CarController>();
        cameraNewPos = GameObject.FindGameObjectWithTag("CameraPosition").transform;
        gameObject.transform.parent = car.transform;
        gameObject.transform.position = cameraNewPos.position;
        gameObject.transform.rotation = cameraNewPos.rotation;
    }
}
