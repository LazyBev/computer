#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <leif/leif.h>

static size_t winw = 1280, winh = 720;

#define WIN_MARGIN 20.0f

int main(void) {
    printf("Init Cherry Glass...");
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(winw, winh, "Cherry Glass", NULL, NULL);

    glfwMakeContextCurrent(window);

    lf_init_glfw(winw, winh, window);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.07f, 0.07f, 0.07f, 0.07f);

        lf_begin();
        lf_div_begin(((vec2s){WIN_MARGIN, WIN_MARGIN}), ((vec2s){winw - WIN_MARGIN * 2.0f, winh - WIN_MARGIN * 2.0f}), true);
        lf_text("Hi!");
        lf_end();
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
