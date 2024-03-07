#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main(void) {

    if (!glfwInit()) {
        cout << "glfwInit failed" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

	if(!gladLoadGL()) {
		cout << "can't load glad" << endl;
		return -1;
	}

    cout << "Renderer: " << glGetString(GL_RENDERER);
    cout << "OpenGL: " << glGetString(GL_VERSION);
	
	glClearColor(0, 1, 0, 1);
	
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    
    _getch();
}