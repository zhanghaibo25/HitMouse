#ifndef _DATA_H_
#define _DATA_H_
//�������õ����ⲿͷ�ļ�
#include<stdio.h>
#include"SDL.h"
#include "SDL_image.h"

//����ͼƬ����·��
#define PATH_BACKGROUND_1 ".\\image\\background_1.png"
#define PATH_BACKGROUND_2 ".\\image\\background_2.png"
#define PATH_BACKGROUND_3 ".\\image\\background_3.png"
#define PATH_BACKGROUND_4 ".\\image\\background_4.png"

//����ͼƬ����·��
#define PATH_SPRITE_NORMAL ".\\image\\spriteNormal.png"
#define PATH_SPRITE_BOMB ".\\image\\spriteBomb.png"
#define PATH_SPRITE_OCTOPUS ".\\image\\spriteOctopus.png"
#define PATH_SPRITE_BEAT ".\\image\\spriteBeat.png"
#define PATH_SPRITE_OCTBEAT ".\\image\\spriteOctBeat.png"

//ը��Ч��ͼƬ����·��
#define PATH_SPRITE_BLAST_1 ".\\image\\spriteBlast_1.png"
#define PATH_SPRITE_BLAST_2 ".\\image\\spriteBlast_2.png"

//īˮͼƬ����·��
#define PATH_SPRITE_INK ".\\image\\spriteInk.png"

//����ͼƬ����·��
#define PATH_NUMBER ".\\image\\number.png"

//��Ϸ���ڴ�С
#define WINDOW_WIDTH 360   //���ڿ��
#define WINDOW_HEIGHT 507   //���ڸ߶�

//����ͼƬ1λ��
#define BACKGROUND_PIC1_W WINDOW_WIDTH
#define BACKGROUND_PIC1_H 222
#define BACKGROUND_PIC1_X 0
#define BACKGROUND_PIC1_Y 0
//����ͼƬ2λ��
#define BACKGROUND_PIC2_W WINDOW_WIDTH
#define BACKGROUND_PIC2_H 117
#define BACKGROUND_PIC2_X 0
#define BACKGROUND_PIC2_Y 202
//����ͼƬ3λ��
#define BACKGROUND_PIC3_W WINDOW_WIDTH
#define BACKGROUND_PIC3_H 120
#define BACKGROUND_PIC3_X 0
#define BACKGROUND_PIC3_Y 298
//����ͼƬ4λ��
#define BACKGROUND_PIC4_W WINDOW_WIDTH
#define BACKGROUND_PIC4_H 109
#define BACKGROUND_PIC4_X 0
#define BACKGROUND_PIC4_Y 398

//����λ����Ϣ
#define SPRITE_W 155
#define SPRITE_H 135
#define SPRITE_1_X -15
#define SPRITE_1_Y 105
#define SPRITE_2_X 105
#define SPRITE_2_Y SPRITE_1_Y
#define SPRITE_3_X 225
#define SPRITE_3_Y SPRITE_1_Y
#define SPRITE_4_X SPRITE_1_X
#define SPRITE_4_Y 200
#define SPRITE_5_X SPRITE_2_X
#define SPRITE_5_Y SPRITE_4_Y
#define SPRITE_6_X SPRITE_3_X
#define SPRITE_6_Y SPRITE_4_Y
#define SPRITE_7_X SPRITE_1_X
#define SPRITE_7_Y 300
#define SPRITE_8_X SPRITE_2_X
#define SPRITE_8_Y SPRITE_7_Y
#define SPRITE_9_X SPRITE_3_X
#define SPRITE_9_Y SPRITE_7_Y

//����ÿ��״̬����֡��
#define FRAMENUMBER_UP 8         //����״̬֡��
#define FRAMENUMBER_WAIT 30   //�ȴ�״̬֡��
#define FRAMENUMBER_DOWN 8  //�½�״̬֡��
#define FRAMENUMBER_BEAT 8     //����״̬֡��
#define FRAMENUMBER_INK 60     //īˮ״̬֡��

//īˮλ��
#define INK_X -5
#define INK_Y -80
#define INK_W 380
#define INK_H 400

//����ÿλ���ִ�С������λ��
#define NUMBER_DST_Y 10
#define NUMBER_DST_W 32
#define NUMBER_DST_H 40

#define NUMBER_SRC_Y 0
#define NUMBER_SRC_W 40
#define NUMBER_SRC_H 50

//���������ö��
typedef enum spriteType
{
    TypeEmpty = 0,      //������
    TypeNormal,           //��ͨ����
    TypeBomb,             //ը������
    TypeOctopus          //����
}SpriteType;

//�����״̬ö��
typedef enum spriteState
{
    StateEmpty = 0,      //��״̬
    StateWait,               //�ȴ�
    StateUp,                 //����
    StateDown,            //�½�
    StateBeat               //����
}SpriteState;

//����Ľṹ��
typedef struct sprite
{
    SpriteType type;         //��������
    SpriteState state;        //����״̬
    SDL_Rect initRect;       //������ʾ����
    int runningTimes;        //����ʱ�����
}Sprite;

//����ͼƬ���ͽṹ��
typedef struct picture
{
    SDL_Texture* pPic;    //ͼƬ����ָ��
    SDL_Rect srcRect;       //Դ����
    SDL_Rect dstRect;       //Ŀ������
}Picture;

#endif 

