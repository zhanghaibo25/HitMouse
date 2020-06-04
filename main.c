#include "interface.h"

int main(void) 
{
    /*
   **************
   **第三次
   **************
   */
    //初始化
    init();
    //运行
    start();
    //释放
    gameFree();

    /*
   **************
   **第二次
   **************
   */
    //Picture pic;
    //
    ////初始化SDL库、创建窗口、渲染器
    //if (0 != initSDL())
    //{
    //    return -1;
    //}
    ////加载图片资源
    //if (0 != loadPicResources())
    //{
    //    return -2;
    //}
    ////绘制窗口
    //paint();
    ////延迟5秒
    //SDL_Delay(5000);
    ////释放图片
    //freePicResources();
    ////释放SDL库、窗口、渲染器
    //freeSDL();



    /*
    **************
    **第一次
    **************
    */
    //SDL_Window* pWindow = NULL;
    //SDL_Renderer* pRenderer = NULL;
    //SDL_Texture* pTexture = NULL;
    //SDL_Rect dstRect;
    ////初始化SDL库，参数，初始化所有子系统
    //if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    //{
    //    printf("初始化失败：%s\n",SDL_GetError);
    //    return -1;
    //}
    //printf("SDL初始化成功！\n");
    ////创建窗口
    //pWindow = SDL_CreateWindow("HitMouse", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,300,500,SDL_WINDOW_SHOWN);
    //if (NULL == pWindow)
    //{
    //    printf("窗口创建失败：%s\n",SDL_GetError);
    //    return -2;
    //}
    //printf("窗口创建成功！\n");
    ////创建渲染器
    //pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    //if (NULL == pRenderer)
    //{
    //    printf("窗口渲染器失败：%s\n", SDL_GetError);
    //    return -3;
    //}
    //printf("窗口渲染器成功！\n");

    ////加载图片并创建纹理
    //pTexture = IMG_LoadTexture(pRenderer, ".\\image\\background_1.png");
    //if (pTexture == NULL)
    //{
    //    printf("加载图片失败：%s\n", IMG_GetError);
    //    return -4;
    //}
    //printf("加载图片成功！\n");
    ////设置图片要显示在窗口中的位置及大小
    //dstRect.x = 0;
    //dstRect.y = 0;
    //dstRect.w = 300;
    //dstRect.h = 200;

    ////将图片拷贝到渲染器中
    //SDL_RenderCopy(pRenderer, pTexture, NULL, &dstRect);
    ////刷新渲染器，实现往窗口中绘制图片
    //SDL_RenderPresent(pRenderer);

    ////延迟5秒
    //SDL_Delay(5000);

    ////释放纹理
    //SDL_DestroyTexture(pTexture);

    ////释放渲染器
    //SDL_DestroyRenderer(pRenderer);
    ////释放窗口
    //SDL_DestroyWindow(pWindow);
    ////退出SDL库
    //SDL_Quit();

    return 0;
}