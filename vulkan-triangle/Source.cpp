#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>

#include<iostream>
#include<stdexcept>
#include<cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Triangle
{
public:
	void run() 
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanUp();
	}

private:
	GLFWwindow* window;

	void initWindow() 
	{
		glfwInit(); // initialize GLFW library

		// dont create opengl context
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "vulkan-triangle", nullptr, nullptr);
	}
	void initVulkan() {}
	void mainLoop() 
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
	}
	void cleanUp() 
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}


}; // class triangle

int main() 
{
	Triangle app;

	try
	{
		app.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
} // main