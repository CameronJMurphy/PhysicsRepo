using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowPlayer : MonoBehaviour
{
    GameObject player;
    float distance = 3;
    // Start is called before the first frame update
    void Start()
    {
        player = FindObjectOfType<CharacterController>().gameObject;
    }

    // Update is called once per frame
    void Update()
    {
        if (player)
        {
            Vector3 temp = player.transform.position - player.transform.forward * distance;
            temp.y = 2.5f;
            transform.position = temp;

			Transform lookAt = player.transform;
			Vector3 pos = lookAt.position;
			pos.y = 1f;
			lookAt.position = pos;
			transform.LookAt(lookAt);
        }
    }
}
