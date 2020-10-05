using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnFlipCar : MonoBehaviour
{
    Animator flipAni;
    // Start is called before the first frame update
    void Start()
    {
        flipAni = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()

    {
        if(Input.GetKey(KeyCode.Z))
        {
            flipAni.SetBool("Trigger", true);
        }
		else
		{
            flipAni.SetBool("Trigger", false);
        }
    }
}
