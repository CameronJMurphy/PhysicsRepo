using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.UI;
using UnityEditor.SceneManagement;
using UnityEngine.SceneManagement;
using System;

public class GameCon : MonoBehaviour
{
    public static GameCon instance;

    int points = 0;
    float timeRemaining = 180;

    public TextMeshProUGUI pointsText;
    public TextMeshProUGUI timeText;

    public Image startPopUp;
    bool pressedOnce = false;

    public Image endPopUp;
    public TextMeshProUGUI endScore;

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
        Time.timeScale = 0;
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
        if(Input.anyKey && !pressedOnce)
		{
            startPopUp.gameObject.SetActive(false);
            Time.timeScale = 1;
            pressedOnce = true;

        }
    }
    //Will play while the game is current finished
    void TimeUp()
	{
        Time.timeScale = 0;
        endPopUp.gameObject.SetActive(true);
        endScore.text = points.ToString() + Environment.NewLine + Environment.NewLine + "Press Esc to go back to menu or press Space to play again.";
        if (Input.GetKeyDown(KeyCode.Escape)) //back to menu
		{
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex - 1);
		}
        else if(Input.GetKeyDown(KeyCode.Space)) //restart level
		{
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
            endPopUp.gameObject.SetActive(false);
        }

    }

    public void AddPoints(int value)
	{
        points += value;
	}

}
