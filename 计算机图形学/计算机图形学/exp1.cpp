#include <GL/glut.h>
//绘制场景  
void RenderScence(void)
{

		//用当前颜色清除窗口  

		glClear(GL_COLOR_BUFFER_BIT);

		//把绘图颜色设置为红色  

		glColor3f(1.0f, 0.0f, 0.0f);

		//用当前的颜色绘制一个填充矩形  

		glRectf(0, 0, 25.0f, -25.0f);

		//刷新绘图命令  

		glFlush();
}
//当窗口改变大小时由GLUT函数库调用  
void ChangeSize(GLsizei w, GLsizei h)
{

		GLfloat aspectRatio;

		//防止被0所除  

		if (h == 0) {

				h = 1;

		}

		//把视口区设置为窗口大小,相对与窗口而言（而窗口的位置在开始运行是已经定义了）  

		//所以（0,0,w,h)中的(0,0)是相对于已经定义好的窗口的左下角的位置。  

		glViewport(0,0,w,h);   

		//glViewport(50, 50, w - 50 , h - 50 );

		//重置坐标系统  
		
		glMatrixMode(GL_PROJECTION);            //切换为透视投影矩阵  

		glLoadIdentity();                       //将透视投影矩阵转换为单位矩阵  
	
		//建立裁剪区域（左右底顶近远）  
		
		aspectRatio = (GLfloat)w / (GLfloat)h;
	
		if (w <= h) {                                //如果宽度小于高度（aspectRatio < 1)  
			
				//glOrtho(-100.0, 100.0, -100/aspectRatio, 100.0/aspectRatio, 1.0, -1.0);  
				//这里转化为二维矩阵
				glOrtho(-30.0, 30.0, -30 / aspectRatio, 30.0 / aspectRatio, 1.0, -1.0);
			
		}
		else {
			
				//glOrtho(-100.0*aspectRatio, 100.0*aspectRatio,-100.0, 100.0, 1.0, -1.0);  
				
				glOrtho(-30.0*aspectRatio, 30.0*aspectRatio, -30.0, 30.0, 1.0, -1.0);
			
		}
		
			glMatrixMode(GL_MODELVIEW);             //切换为平行投影矩阵  
		
			glLoadIdentity();                       //将平行投影矩阵转换为单位矩阵  
}
//设置渲染状态  
void SetupRC(void)
{

		//设置清除颜色  

		glClearColor(0.0f, 0.6f, 1.0f, 1.0f);
}
//主程序入口  
int main(int argc, char* argv[])
{

		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

		glutInitWindowPosition(100, 300);

		glutInitWindowSize(400, 400);

		glutCreateWindow("coder");                  //创建一个窗口  

		glutDisplayFunc(RenderScence);                  //注册回调函数  

		glutReshapeFunc(ChangeSize);

		SetupRC();                                      //设置初始化状态（有些状态只需要设置一次）  

		glutMainLoop();                                 //开始循环运行，显示绘图。  

		return 0;
}