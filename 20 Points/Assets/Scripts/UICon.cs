using UnityEngine;
using UnityEngine.SceneManagement;

public class UICon : MonoBehaviour
{
    public void PlayGame()
	{
		SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
	}

	public void ExitGame()
	{
		Application.Quit();
	}
}
