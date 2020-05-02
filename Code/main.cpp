#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
using namespace std;

void OnFrameBufferSizeChange(GLFWwindow* pWindow, int nWidth, int nHeight);

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
const char* TITLE_NAME = "MyBaseOpenGLProj";

int main()
{
	cout << "SoftRendererY Init" << endl;

	glfwInit();

	// opengl3.x不支持glDrawPixels，如果要用需要将这段注释
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* pWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, TITLE_NAME, nullptr, nullptr);
	if (!pWindow)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(pWindow);
	glfwSetFramebufferSizeCallback(pWindow, OnFrameBufferSizeChange);

	// 加载glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to Init GLAD" << endl;
		glfwTerminate();
		return -1;
	}

	cout << "SoftRendererY Init Succ" << endl;
	while (!glfwWindowShouldClose(pWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}


void OnFrameBufferSizeChange(GLFWwindow* pWindow, int nWidth, int nHeight)
{
	if (pWindow)
	{
		glViewport(0, 0, nWidth, nHeight);
	}
}
