#include <GL/glut.h>

void main(int argc,char** argv){
  glutInit(&argc,argv);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow("Hello World");
  glutSetCursor(GLUT_CURSOR_INFO);
  glutFullScreen();
  glutMainLoop();
}
