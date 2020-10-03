using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class GameCon : MonoBehaviour
{
    public static GameCon instance;

    int points = 0;
    float timeRemaining = 60;

    public TextMeshProUGUI pointsText;
    public TextMeshProUGUI timeText;

	private void Awake()
	{
        if(instance == null)
		{
            instance = this;
		}
		else
		{
            Destroy(this);
		}
    }

    // Update is called once per frame
    void Update()
    {
        timeRemaining -= Time.deltaTime;
        pointsText.text = "Points: " + points.ToString();
        timeText.text = "Time Remaining: " + ((int)timeRemaining).ToString();
        if(timeRemaining < 0)
		{
            TimeUp();
		}
    }

    void TimeUp()
	{
        Time.timeScale = 0;
	}

    public void AddPoints(int value)
	{
        points += value;
	}

}
