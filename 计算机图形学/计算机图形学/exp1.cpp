#include <GL/glut.h>
//���Ƴ���  
void RenderScence(void)
{

		//�õ�ǰ��ɫ�������  

		glClear(GL_COLOR_BUFFER_BIT);

		//�ѻ�ͼ��ɫ����Ϊ��ɫ  

		glColor3f(1.0f, 0.0f, 0.0f);

		//�õ�ǰ����ɫ����һ��������  

		glRectf(0, 0, 25.0f, -25.0f);

		//ˢ�»�ͼ����  

		glFlush();
}
//�����ڸı��Сʱ��GLUT���������  
void ChangeSize(GLsizei w, GLsizei h)
{

		GLfloat aspectRatio;

		//��ֹ��0����  

		if (h == 0) {

				h = 1;

		}

		//���ӿ�������Ϊ���ڴ�С,����봰�ڶ��ԣ������ڵ�λ���ڿ�ʼ�������Ѿ������ˣ�  

		//���ԣ�0,0,w,h)�е�(0,0)��������Ѿ�����õĴ��ڵ����½ǵ�λ�á�  

		glViewport(0,0,w,h);   

		//glViewport(50, 50, w - 50 , h - 50 );

		//��������ϵͳ  
		
		glMatrixMode(GL_PROJECTION);            //�л�Ϊ͸��ͶӰ����  

		glLoadIdentity();                       //��͸��ͶӰ����ת��Ϊ��λ����  
	
		//�����ü��������ҵ׶���Զ��  
		
		aspectRatio = (GLfloat)w / (GLfloat)h;
	
		if (w <= h) {                                //������С�ڸ߶ȣ�aspectRatio < 1)  
			
				//glOrtho(-100.0, 100.0, -100/aspectRatio, 100.0/aspectRatio, 1.0, -1.0);  
				//����ת��Ϊ��ά����
				glOrtho(-30.0, 30.0, -30 / aspectRatio, 30.0 / aspectRatio, 1.0, -1.0);
			
		}
		else {
			
				//glOrtho(-100.0*aspectRatio, 100.0*aspectRatio,-100.0, 100.0, 1.0, -1.0);  
				
				glOrtho(-30.0*aspectRatio, 30.0*aspectRatio, -30.0, 30.0, 1.0, -1.0);
			
		}
		
			glMatrixMode(GL_MODELVIEW);             //�л�Ϊƽ��ͶӰ����  
		
			glLoadIdentity();                       //��ƽ��ͶӰ����ת��Ϊ��λ����  
}
//������Ⱦ״̬  
void SetupRC(void)
{

		//���������ɫ  

		glClearColor(0.0f, 0.6f, 1.0f, 1.0f);
}
//���������  
int main(int argc, char* argv[])
{

		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

		glutInitWindowPosition(100, 300);

		glutInitWindowSize(400, 400);

		glutCreateWindow("coder");                  //����һ������  

		glutDisplayFunc(RenderScence);                  //ע��ص�����  

		glutReshapeFunc(ChangeSize);

		SetupRC();                                      //���ó�ʼ��״̬����Щ״ֻ̬��Ҫ����һ�Σ�  

		glutMainLoop();                                 //��ʼѭ�����У���ʾ��ͼ��  

		return 0;
}