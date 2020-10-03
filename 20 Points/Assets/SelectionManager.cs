using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class SelectionManager : MonoBehaviour
{
    public TextMeshProUGUI displayPointValue;

    // Update is called once per frame
    void Update()
    {
        var ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;
        if(Physics.Raycast(ray, out hit))
		{
            Transform target = hit.transform;
            if (target != null)
            {
                Target targetScript = target.gameObject.GetComponentInParent<Target>();
                if (targetScript != null)
                {
                    displayPointValue.text = "Value: " + targetScript.pointValue.ToString();
                }
            }

		}
    }
}
