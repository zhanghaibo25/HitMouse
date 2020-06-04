#include "interface.h"

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

Picture g_picBackGround_1;
Picture g_picBackGround_2;
Picture g_picBackGround_3;
Picture g_picBackGround_4;

 Picture g_picSpriteNormal;               //普通地鼠图片
 Picture g_picSpriteBomb;                 //炸弹地鼠图片
 Picture g_picSpriteBeat;                    //被打地鼠图片
 Picture g_picSpriteOctopus;              //章鱼图片
 Picture g_picSpriteOctBeat;               //章鱼被打图片

 Picture g_picSpriteBlast1;                  //爆炸图片1
 Picture g_picSpriteBlast2;                  //爆炸图片2

 Picture g_picSpriteInk;                      //墨汁图片

 Picture g_picNumber;                       //数字图片

 extern int g_nScore;                          //分数

 extern Sprite g_spriteArr[9];             //精灵数组
 extern int g_nInkTimes;                     //墨水计时器
/*
**函数：int initSDL(void)
**作用：初始化SDL库及窗口、渲染器
**返回：0表示初始化成功，非0表示初始化失败
*/
int initSDL(void)
{
    //初始化SDL开发库
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        printf("SDL初始化失败：&s\n",SDL_GetError());
        return -1;
    }
    printf("SDL初始化成功！\n");

    //创建窗口
    g_pWindow = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (NULL == g_pWindow)
    {
        printf("窗口创建失败：&s\n", SDL_GetError());
        return -2;
    }

    //创建渲染器
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 
                                SDL_RENDERER_ACCELERATED);
    if (NULL == g_pRenderer)
    {
        printf("渲染器创建失败：&s\n", SDL_GetError());
        return -3;
    }

    return 0;
}

//名称：void freeSDL(void)
//说明：释放SDL库、窗口、渲染器
void freeSDL(void)
{
    //释放渲染器
    SDL_DestroyRenderer(g_pRenderer);
    printf("渲染器释放！\n");

    //释放窗口
    SDL_DestroyWindow(g_pWindow);
    printf("窗口释放！\n");

    //退出SDL库
    SDL_Quit();
    printf("SDL库已退出！\n");
}

/*
**名称：Picture loadPic(const char * path)
**说明：加载一幅图片
**参数：path本地图片路径
**返回：图片结构体
*/
Picture loadPic(const char* path)
{
    Picture pic;
    //加载一幅图片
    pic.pPic = IMG_LoadTexture(g_pRenderer, path);
    if (NULL == pic.pPic)
    {
        printf("图片创建失败：%s\n", SDL_GetError());
    }
    return pic;
}

/*
**说明：设置一幅图片的目标显示区域
**参数：picture图片结构体指针
*/
void setPicDstRect(Picture* picture, int x, int y, int w, int h)
{
    picture->dstRect.x = x;
    picture->dstRect.y = y;
    picture->dstRect.w = w;
    picture->dstRect.h = h;
}

/*
**说明：设置一幅图片的源读取区域
**参数：picture图片结构体指针
*/
void setPicSrcRect(Picture* picture, int x, int y, int w, int h)
{
    picture->srcRect.x = x;
    picture->srcRect.y = y;
    if (0 == w || 0 == h)
    {
        SDL_QueryTexture(picture->pPic, NULL, NULL, &(picture->srcRect.w),
            &(picture->srcRect.h));
    }
    else
    {
        picture->srcRect.w = w;
        picture->srcRect.h = h;
    }
}

/*
**说明：加载程序所需要的图片资源
**返回：0表示加载成功，非0表示加载失败
*/
int loadPicResources(void)
{
    //加载背景图片1
    g_picBackGround_1 = loadPic(PATH_BACKGROUND_1);
    if (g_picBackGround_1.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picBackGround_1, 0, 0, 0, 0);
    setPicDstRect(&g_picBackGround_1,
        BACKGROUND_PIC1_X, BACKGROUND_PIC1_Y,
        BACKGROUND_PIC1_W, BACKGROUND_PIC1_H);
    //加载背景图片2
    g_picBackGround_2 = loadPic(PATH_BACKGROUND_2);
    if (g_picBackGround_2.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picBackGround_2, 0, 0, 0, 0);
    setPicDstRect(&g_picBackGround_2,
        BACKGROUND_PIC2_X, BACKGROUND_PIC2_Y,
        BACKGROUND_PIC2_W, BACKGROUND_PIC2_H);
    //加载背景图片3
    g_picBackGround_3 = loadPic(PATH_BACKGROUND_3);
    if (g_picBackGround_3.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picBackGround_3, 0, 0, 0, 0);
    setPicDstRect(&g_picBackGround_3,
        BACKGROUND_PIC3_X, BACKGROUND_PIC3_Y,
        BACKGROUND_PIC3_W, BACKGROUND_PIC3_H);
    //加载背景图片4
    g_picBackGround_4 = loadPic(PATH_BACKGROUND_4);
    if (g_picBackGround_4.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picBackGround_4, 0, 0, 0, 0);
    setPicDstRect(&g_picBackGround_4,
        BACKGROUND_PIC4_X, BACKGROUND_PIC4_Y,
        BACKGROUND_PIC4_W, BACKGROUND_PIC4_H);

    //普通地鼠图片
    g_picSpriteNormal = loadPic(PATH_SPRITE_NORMAL);
    if (g_picSpriteNormal.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteNormal, 0, 0, 0, 0);

    //炸弹地鼠图片
    g_picSpriteBomb = loadPic(PATH_SPRITE_BOMB);
    if (g_picSpriteBomb.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteBomb, 0, 0, 0, 0);

    //被打地鼠图片
    g_picSpriteBeat = loadPic(PATH_SPRITE_BEAT);
    if (g_picSpriteBeat.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteBeat, 0, 0, 0, 0);

    //章鱼图片
    g_picSpriteOctopus = loadPic(PATH_SPRITE_OCTOPUS);
    if (g_picSpriteOctopus.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteOctopus, 0, 0, 0, 0);

    //章鱼被打图片
    g_picSpriteOctBeat = loadPic(PATH_SPRITE_OCTBEAT);
    if (g_picSpriteOctBeat.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteOctBeat, 0, 0, 0, 0);

    //爆炸图片1
    g_picSpriteBlast1 = loadPic(PATH_SPRITE_BLAST_1);
    if (g_picSpriteBlast1.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteBlast1, 0, 0, 0, 0);

    //爆炸图片2
    g_picSpriteBlast2 = loadPic(PATH_SPRITE_BLAST_2);
    if (g_picSpriteBlast2.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteBlast2, 0, 0, 0, 0);

    //墨汁图片
    g_picSpriteInk = loadPic(PATH_SPRITE_INK);
    if (g_picSpriteInk.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picSpriteInk, 0, 0, 0, 0);
    setPicDstRect(&g_picSpriteInk, INK_X, INK_Y, INK_W, INK_H );

    //加载数字图片
    g_picNumber = loadPic(PATH_NUMBER);
    if (g_picNumber.pPic == NULL)
    {
        return -1;
    }
    setPicSrcRect(&g_picNumber, 0, NUMBER_DST_Y, NUMBER_DST_W, 
        NUMBER_DST_H);
    setPicDstRect(&g_picNumber, 0, NUMBER_SRC_Y, NUMBER_SRC_W,
        NUMBER_SRC_H);

    return 0;
}

//说明：释放程序加载的图片资源
int freePicResources(void)
{
    //释放背景图片
    SDL_DestroyTexture(g_picBackGround_1.pPic);
    SDL_DestroyTexture(g_picBackGround_2.pPic);
    SDL_DestroyTexture(g_picBackGround_3.pPic);
    SDL_DestroyTexture(g_picBackGround_4.pPic);

    //释放精灵图片
    SDL_DestroyTexture(g_picSpriteNormal.pPic);
    SDL_DestroyTexture(g_picSpriteBomb.pPic);
    SDL_DestroyTexture(g_picSpriteBeat.pPic);
    SDL_DestroyTexture(g_picSpriteOctopus.pPic);
    SDL_DestroyTexture(g_picSpriteOctBeat.pPic);

    //释放特效图片                  
    SDL_DestroyTexture(g_picSpriteBlast1.pPic);
    SDL_DestroyTexture(g_picSpriteBlast2.pPic);
    SDL_DestroyTexture(g_picSpriteInk.pPic);

    //释放特效图片                  
    SDL_DestroyTexture(g_picNumber.pPic);
}

/*
**说明：往渲染器绘制一幅图片
**返回：picture 图片结构体指针
*/
void paintPic(Picture* picture)
{
    SDL_RenderCopy(g_pRenderer, picture->pPic, &(picture->srcRect),
        &(picture->dstRect));
}

//说明：绘制窗口
void paint(void)
{
    //绘制背景图片 
    paintPic(&g_picBackGround_1);
    paintSprite(0);
    paintPic(&g_picBackGround_2);
    paintSprite(1);
    paintPic(&g_picBackGround_3);
    paintSprite(2);
    paintPic(&g_picBackGround_4);

    paintBlast();

    paintInk();

    paintScore();
    //更新渲染器图像
    SDL_RenderPresent(g_pRenderer);
}

/*
*********************************
**说明：绘制精灵
**参数：nLayer精灵所属的层数
*********************************
*/
void paintSprite(int nLayer)
{
    int i = 0;
    Picture* pPic = NULL;
    //根据层数，遍历指定层的三个精灵
    for (i = nLayer * 3; i < ((nLayer + 1) * 3); i++)
    {
        if (g_spriteArr[i].type == TypeEmpty)
        {
            continue;
        }
        else if (g_spriteArr[i].type == TypeOctopus)
        {
            if (g_spriteArr[i].state == StateBeat)
            {
                pPic = &g_picSpriteOctBeat;
            }
            else
            {
                pPic = &g_picSpriteOctopus;
            }
        }
        else if (g_spriteArr[i].type == TypeBomb)
        {
            if (g_spriteArr[i].state == StateBeat)
            {
                pPic = &g_picSpriteBeat;
            }
            else
            {
                pPic = &g_picSpriteBomb;
            }
        }
        else
        {
            if (g_spriteArr[i].state == StateBeat)
            {
                pPic = &g_picSpriteBeat;
            }
            else
            {
                pPic = &g_picSpriteNormal;
            }
        }

        //根据精灵的计数器计数计算精灵出现的位置
        pPic->dstRect = g_spriteArr[i].initRect;
        if (g_spriteArr[i].state == StateUp)
        {
            pPic->dstRect.y = 
                (g_spriteArr[i].initRect.y + g_spriteArr[i].initRect.h)
                - g_spriteArr[i].initRect.h / FRAMENUMBER_UP
                * g_spriteArr[i].runningTimes;
        }
        if (g_spriteArr[i].state == StateDown)
        {
            pPic->dstRect.y = 
                g_spriteArr[i].initRect.y + 
                g_spriteArr[i].initRect.h / FRAMENUMBER_DOWN
                * g_spriteArr[i].runningTimes;
        }

        //绘制精灵图片
        paintPic(pPic);
    }
}

/*
*********************************
**说明：绘制爆炸
*********************************
*/
void paintBlast(void)
{
    int i = 0;
    Picture* pPic = NULL;
    for (i = 0; i < 9; i++)
    {
        //非炸弹地鼠非被打
        if (g_spriteArr[i].type != TypeBomb
            || g_spriteArr[i].state!=StateBeat)
        {
            continue;
        }
        if (g_spriteArr[i].runningTimes < FRAMENUMBER_BEAT / 2)
        {
            pPic = &g_picSpriteBlast1;
        }
        else
        {
            pPic = &g_picSpriteBlast2;
        }
        pPic->dstRect = g_spriteArr[i].initRect;
        paintPic(pPic);
    }
}

/*
*********************************
**说明：绘制爆炸
*********************************
*/
void paintInk(void)
{
    int i = 0;
    Picture* pPic = NULL;
    if (0 == g_nInkTimes)
    {
        return;
    }
    pPic = &g_picSpriteInk;

    //设置图片透明度
    paintPic(pPic);
    g_nInkTimes++;
    if (g_nInkTimes > FRAMENUMBER_INK)
    {
        g_nInkTimes = 0;
    }
}

/*
*********************************
**说明：绘制爆炸
*********************************
*/
void paintScore(void)
{
    int nScoreBit = 0;
    int nCurScore = g_nScore;
    int nCurBitNumber = 0;
    int i, j;

    while (nCurBitNumber > 0)
    {
        nCurScore /= 10;
        nScoreBit++;
    }

    if (g_nScore == 0)
    {
        nScoreBit = 1;
    }

    for (i = 0; i < nScoreBit; i++)
    {
        g_picNumber.dstRect.x = (WINDOW_WIDTH - nScoreBit * NUMBER_DST_W)
            / 2 + i * NUMBER_DST_W;

        nCurScore = g_nScore;
        for (j = 1; j < (nScoreBit - i); j++)
        {
            nCurScore / 10;
        }
        nCurBitNumber = nCurScore % 10;
        g_picNumber.srcRect.x = nCurBitNumber * NUMBER_SRC_W;
        paintPic(&g_picNumber);
    }
}