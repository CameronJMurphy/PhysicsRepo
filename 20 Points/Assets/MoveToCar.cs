using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveToCar : MonoBehaviour
{
    CarController car;
    public Transform cameraNewPos;
    

    // Start is called before the first frame update
    void Start()
    {
        car = FindObjectOfType<CarController>();
    }
    public void Invoke()
	{
        gameObject.transform.parent = car.transform;
        gameObject.transform.position = cameraNewPos.position;
        gameObject.transform.rotation = cameraNewPos.rotation;
    }
}
