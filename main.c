#include "interface.h"

int main(void) 
{
    /*
   **************
   **������
   **************
   */
    //��ʼ��
    init();
    //����
    start();
    //�ͷ�
    gameFree();

    /*
   **************
   **�ڶ���
   **************
   */
    //Picture pic;
    //
    ////��ʼ��SDL�⡢�������ڡ���Ⱦ��
    //if (0 != initSDL())
    //{
    //    return -1;
    //}
    ////����ͼƬ��Դ
    //if (0 != loadPicResources())
    //{
    //    return -2;
    //}
    ////���ƴ���
    //paint();
    ////�ӳ�5��
    //SDL_Delay(5000);
    ////�ͷ�ͼƬ
    //freePicResources();
    ////�ͷ�SDL�⡢���ڡ���Ⱦ��
    //freeSDL();



    /*
    **************
    **��һ��
    **************
    */
    //SDL_Window* pWindow = NULL;
    //SDL_Renderer* pRenderer = NULL;
    //SDL_Texture* pTexture = NULL;
    //SDL_Rect dstRect;
    ////��ʼ��SDL�⣬��������ʼ��������ϵͳ
    //if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    //{
    //    printf("��ʼ��ʧ�ܣ�%s\n",SDL_GetError);
    //    return -1;
    //}
    //printf("SDL��ʼ���ɹ���\n");
    ////��������
    //pWindow = SDL_CreateWindow("HitMouse", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,300,500,SDL_WINDOW_SHOWN);
    //if (NULL == pWindow)
    //{
    //    printf("���ڴ���ʧ�ܣ�%s\n",SDL_GetError);
    //    return -2;
    //}
    //printf("���ڴ����ɹ���\n");
    ////������Ⱦ��
    //pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    //if (NULL == pRenderer)
    //{
    //    printf("������Ⱦ��ʧ�ܣ�%s\n", SDL_GetError);
    //    return -3;
    //}
    //printf("������Ⱦ���ɹ���\n");

    ////����ͼƬ����������
    //pTexture = IMG_LoadTexture(pRenderer, ".\\image\\background_1.png");
    //if (pTexture == NULL)
    //{
    //    printf("����ͼƬʧ�ܣ�%s\n", IMG_GetError);
    //    return -4;
    //}
    //printf("����ͼƬ�ɹ���\n");
    ////����ͼƬҪ��ʾ�ڴ����е�λ�ü���С
    //dstRect.x = 0;
    //dstRect.y = 0;
    //dstRect.w = 300;
    //dstRect.h = 200;

    ////��ͼƬ��������Ⱦ����
    //SDL_RenderCopy(pRenderer, pTexture, NULL, &dstRect);
    ////ˢ����Ⱦ����ʵ���������л���ͼƬ
    //SDL_RenderPresent(pRenderer);

    ////�ӳ�5��
    //SDL_Delay(5000);

    ////�ͷ�����
    //SDL_DestroyTexture(pTexture);

    ////�ͷ���Ⱦ��
    //SDL_DestroyRenderer(pRenderer);
    ////�ͷŴ���
    //SDL_DestroyWindow(pWindow);
    ////�˳�SDL��
    //SDL_Quit();

    return 0;
}