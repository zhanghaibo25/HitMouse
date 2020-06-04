#include "interface.h"
#include "logic.h"
#include <stdlib.h>
#include <time.h>

Sprite g_spriteArr[9];    //精灵数组
int g_nInkTimes = 0;     //墨水计时器
int g_nScore = 0;          //分数
/*
********************************
**作用：游戏初始化
********************************
*/
int init(void) 
{
    //初始化SDL库
    if (initSDL() != 0)
    {
        return -1;
    }

    //加载图片资源
    if (loadPicResources() != 0)
    {
        return -2;
    }

    //初始化精灵数组
    initSprite();

    return 0;
}
/*
********************************
**作用：游戏资源释放
********************************
*/
void gameFree(void)
{
    //释放图片
    freePicResources();

    //退出SDL库，释放窗口、渲染器
    freeSDL();
}
/*
********************************
**作用：定时器响应函数
**每次调用函数都会执行paint()函数完成窗口界面的绘制
********************************
*/
Uint32 timerFun(Uint32 interval, void* param)
{
    static int nTime = 0;
    nTime++;
    if (nTime == 10)
    {
        int i = 0;
        nTime = 0;
        srand((unsigned int)time(0));
        while (i++ != 9)
        {
            int nSprite = rand() % 9;
            int nType = rand() % 5;
            if (g_spriteArr[i].type == TypeEmpty)
            {
                if (nType == 0)
                {
                    g_spriteArr[nSprite].type = TypeBomb;
                }
                else if (nType == 1)
                {
                    g_spriteArr[nSprite].type = TypeOctopus;
                }
                else
                {
                    g_spriteArr[nSprite].type = TypeNormal;
                }
                //设置状态为上升状态
                g_spriteArr[nSprite].state= StateUp;
                break;
            }
        }
    }
    //绘制窗口
    paint();

    //精灵运动
    spriteRun();

    return interval;
}
/*
********************************
**作用：游戏开始（添加定时器、时间循环等）
********************************
*/
void start(void)
{
    SDL_Event event;   //事件类型变量
    int nQuit = 0;         //退出标识，0循环，非0退出循环

    //添加定时器函数
    SDL_AddTimer(85, timerFun, NULL);

    //从消息队列中循环取得事件
    while (nQuit == 0)
    {
        while (SDL_PollEvent(&event))   //获取事件
        {
            switch (event.type)                 //事件的类别
            {
            case SDL_QUIT:                       //退出事件
                nQuit = 1;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseButtonEvent(&event);
                break;
            default:
                break;
            }
        }
    }
}
/*
********************************
**作用：游戏初始化
********************************
*/
void initSprite(void)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        g_spriteArr[i].type = TypeEmpty;
        g_spriteArr[i].state = StateEmpty;
        g_spriteArr[i].initRect.w = SPRITE_W;
        g_spriteArr[i].initRect.h = SPRITE_H;
        g_spriteArr[i].runningTimes = 0;

        switch (i)
        {
        case 0:
            g_spriteArr[i].initRect.x = SPRITE_1_X;
            g_spriteArr[i].initRect.w = SPRITE_1_Y;
            break;
        case 1:
            g_spriteArr[i].initRect.x = SPRITE_2_X;
            g_spriteArr[i].initRect.w = SPRITE_2_Y;
            break;
        case 2:
            g_spriteArr[i].initRect.x = SPRITE_3_X;
            g_spriteArr[i].initRect.w = SPRITE_3_Y;
            break;
        case 3:
            g_spriteArr[i].initRect.x = SPRITE_4_X;
            g_spriteArr[i].initRect.w = SPRITE_4_Y;
            break;
        case 4:
            g_spriteArr[i].initRect.x = SPRITE_5_X;
            g_spriteArr[i].initRect.w = SPRITE_5_Y;
            break;
        case 5:
            g_spriteArr[i].initRect.x = SPRITE_6_X;
            g_spriteArr[i].initRect.w = SPRITE_6_Y;
            break;
        case 6:
            g_spriteArr[i].initRect.x = SPRITE_7_X;
            g_spriteArr[i].initRect.w = SPRITE_7_Y;
            break;
        case 7:
            g_spriteArr[i].initRect.x = SPRITE_8_X;
            g_spriteArr[i].initRect.w = SPRITE_8_Y;
            break;
        case 8:
            g_spriteArr[i].initRect.x = SPRITE_9_X;
            g_spriteArr[i].initRect.w = SPRITE_9_Y;
            break;
        }
    }
}

/*
********************************
**作用：精灵运动
********************************
*/
void spriteRun(void)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        //空类型返回
        if (g_spriteArr[i].type == TypeEmpty)
        {
            continue;
        }

        //状态计数器
        g_spriteArr[i].runningTimes++;
        if (g_spriteArr[i].state == StateUp)
        {
            if (g_spriteArr[i].runningTimes == FRAMENUMBER_UP)
            {
                //帧数达到上升的最大帧数，状态变为等待
                g_spriteArr[i].runningTimes = 0;
                g_spriteArr[i].state = StateWait;
            }
        }
        else if (g_spriteArr[i].state == StateWait)
        {
            if (g_spriteArr[i].runningTimes == FRAMENUMBER_WAIT)
            {
                //帧数达到等待的最大帧数，状态变为下降
                g_spriteArr[i].runningTimes = 0;
                g_spriteArr[i].state = StateDown;
            }
        }
        if (g_spriteArr[i].state == StateDown)
        {
            if (g_spriteArr[i].runningTimes == FRAMENUMBER_DOWN)
            {
                //帧数达到下降的最大帧数，状态类型计数器都置0
                g_spriteArr[i].runningTimes = 0;
                g_spriteArr[i].state = StateEmpty;
                g_spriteArr[i].type = TypeEmpty;
            }
        }
        else
        {
            if (g_spriteArr[i].runningTimes == FRAMENUMBER_BEAT)
            {
                //帧数达到上升的最大帧数，状态变为等待
                g_spriteArr[i].runningTimes = 0;
                g_spriteArr[i].state = StateWait;
                g_spriteArr[i].type= TypeEmpty;
            }
        }
    }
}

/*
********************************
**作用：鼠标点击事件
********************************
*/
void mouseButtonEvent(const SDL_Event* pEvent)
{
    int i;
    if (pEvent->button.button != SDL_BUTTON_LEFT
        ||pEvent->button.type!=SDL_MOUSEBUTTONDOWN)
    {
        return;
    }
    for (i = 0; i < 9; i++)
    {
        if ((pEvent->button.x >= g_spriteArr[i].initRect.x)
            && (pEvent->button.x <= g_spriteArr[i].initRect.x
                + g_spriteArr[i].initRect.w)
            && (pEvent->button.y >= g_spriteArr[i].initRect.y)
            && (pEvent->button.y <= g_spriteArr[i].initRect.y
                + g_spriteArr[i].initRect.h))
        {
            if (g_spriteArr[i].state == StateWait)
            {
                g_spriteArr[i].state = StateBeat;
                g_spriteArr[i].runningTimes = 0;
                if (g_spriteArr[i].type == TypeOctopus)
                {
                    g_nInkTimes = 1;
                }
                //更新分数
                updateScore(g_spriteArr[i].type);
            }
        }
    }
}

/*
********************************
**作用：鼠标点击事件
********************************
*/
void updateScore(SpriteType type)
{
    if (type == TypeNormal)
    {
        g_nScore += 2;
    }
    else if (type == TypeBomb)
    {
        g_nScore -= 3;
    }
    if (g_nScore < 0)
    {
        g_nScore = 0;
    }
}