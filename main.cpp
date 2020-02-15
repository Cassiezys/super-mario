#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<pthread.h>

#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")


pthread_t BGM;
PIMAGE mapimage,mari[8],ar[3],wal[5],ques,water,moguimage,mar[2],map1image[4],map2image[4],mon, goldi[4],bg,di,star[4],prin,love,bad1,ambulen[4],lunyiboy[2],mushroom,monster[2],tor[2];

/****强行标记所用***/
int gamelevel = 0;  // 计算关卡
int itime, mark = 100 ;  // 开始游戏否
int temp ;
int conting=1;
int alpha = 0, da = 1;  //  淡入 淡出标记
int gameState = 0;
int music_control = 1;
int music_num=0;
int music_begin = 1;
int sign =100;  // 标记音效
int map_sign = 0;   //判断第二关摔了没
int te = 0;
int am = 0;

/***** 初始值  **********/
int life_num=3;
int score_num=0;
int game_score=0;
int second;

/*****    金币的转圈 地图的转动 ******/
int g=0;
int k = 0;

/*****  地图的的显示****/
int map[18][30];
int map2[18][30];
void init_map()
{
    int i =0,j=0;
    if(gamelevel == 1)
    {
        int map1[18][30]=
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,2,2,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
            1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
            1,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,0,1,
            1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,21,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1

        };

        for(i=0; i<18; i++)

        {
            for(j=0; j<30; j++)
            {
                map[i][j] = map1[i][j];
            }
        }
    }

    else if(gamelevel == 2)
    {
        int map3[18][30]=
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,
            1,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,2,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1,
            1,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,0,0,0,0,0,0,0,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1

        };


        for(i=0; i<18; i++)

        {
            for(j=0; j<30; j++)
            {
                map[i][j] = map3[i][j];
            }
        }
    }
}

PIMAGE wel[5],starimage[2], marion[2],bgl,mu,img,situa;
mouse_msg ms;
void init_wel()
{
    int i;
    initgraph(1024,768);
    for(i=0; i<5; i++)
    {
        wel[i] = newimage();
    }
    for(i=0; i<2; i++)
    {
        starimage[i] = newimage();
        marion[i] = newimage();
    }
    bgl = newimage();
    bad1 = newimage();
    mu = newimage();
    img = newimage();
    situa=newimage();

    getimage(situa,"c\\welcom\\situation2.png");
    getimage(img,"c\\welcom\\1.png");
    getimage(bad1,"c\\bad\\bad1.png");
    getimage(wel[0],"c\\welcom\\wel1.0.jpg");
    getimage(wel[1],"c\\welcom\\wel1.1.jpg");
    getimage(wel[2],"c\\welcom\\wel1.2.jpg");
    getimage(wel[3],"c\\welcom\\wel1.3.jpg");
    getimage(wel[4],"c\\welcom\\wel1.4.jpg");
    getimage(starimage[0],"c\\welcom\\star.png");
    getimage(starimage[1],"c\\welcom\\star1.png");
    getimage(marion[0],"c\\welcom\\mario1.png");
    getimage(marion[1],"c\\welcom\\mario2.png");
    getimage(bgl,"c\\welcom\\bgl.png");
    getimage(mu,"c\\welcom\\music.png");
}

void* play_clickmusic(void *ret)
{
    int temp=*(int *)ret;
    if(temp==0)
    {
        mciSendString(TEXT("open music\\jump.mp3 alias jump"), NULL, 0, NULL);
        mciSendString(TEXT("play jump"), NULL, 0, NULL);
    }
    if(temp == 1)
    {
        mciSendString(TEXT("open music\\vic.mp3 alias vic"), NULL, 0, NULL);
        mciSendString(TEXT("play vic"), NULL, 0, NULL);
    }
    if(temp == 2)
    {
        mciSendString(TEXT("open music\\glod.mp3 alias gold"), NULL, 0, NULL);
        mciSendString(TEXT("play gold"), NULL, 0, NULL);
    }
    if(temp == 3)
    {
        mciSendString(TEXT("open music\\die.mp3 alias die"), NULL, 0, NULL);
        mciSendString(TEXT("play die"), NULL, 0, NULL);
    }
    if(temp == 4)
    {
        mciSendString(TEXT("open music\\change.mp3 alias change"), NULL, 0, NULL);
        mciSendString(TEXT("play change"), NULL, 0, NULL);
    }
    if(temp == 7)
    {
        mciSendString(TEXT("open music\\monsfeat.mp3 alias monsfeat"), NULL, 0, NULL);
        mciSendString(TEXT("play monsfeat"), NULL, 0, NULL);
    }

}

void show_situation()
{

    while(1)
    {
        bar(0,0,1024,768);
        putimage_transparent(NULL,marion[1],0,0,BLACK);
        /***介绍游戏玩法****/
        putimage(0,0,situa);
        setfillcolor(BLACK);
        bar(80,700,200,750,NULL);
        setfont(40, 0,"宋体");
        setbkmode(TRANSPARENT);
        setcolor(WHITE);
        outtextxy(100,700,"Back");
        while(mousemsg())      // 检测当时是否有鼠标消息
        {
            ms=getmouse();
            if(ms.x>80 && ms.x<200 && ms.y >700 && ms.y <750)
            {
                setfillcolor(LIGHTGRAY);
                bar(80,700,200,750,NULL);
                setfont(40, 0,"宋体");
                setbkmode(TRANSPARENT);
                setcolor(BLUE);
                outtextxy(100,700,"Back");
            }
        }
        delay_fps(60);
        ms=getmouse();
        if(ms.is_left() && ms.x>80 && ms.x<200 && ms.y >700 && ms.y <750)
        {
            gameState = 0;
            break;
        }
    }
}

void TIME()
{
    int time;
    time = clock();
    second = time/1000;
}

typedef struct Stone
{
    int x,y;
    int alive;
} stone;
stone sto[2], gold[20];

typedef struct Role
{
    int x,y;
    int arrow;
    int dex;
    int speed;
    int high;
    int alive;
    int victory;
    //int lun;

} role;

role mario, mogu, qu[2], prins,monste;
enum arrow
{right, left};

void init_pic()
{
    initgraph(800,500);
    int i;
    mapimage = newimage();

    for(i=0; i<8; i++)
    {
        mari[i] = newimage();
    }
    for(i=0; i<2; i++)
    {
        mar[i] = newimage();
        lunyiboy[i] = newimage();
       monster[i] = newimage();
       tor[i] = newimage();
    }
    for(i=0; i<5; i++)
    {
        wal[i] = newimage();
    }
    for(i=0; i<4; i++)
    {
        goldi[i] = newimage();
        star[i] = newimage();
        map1image[i] = newimage();
        map2image[i] = newimage();
        ambulen[i] = newimage();
    }
    for(i=0;i<3;i++)
    {
        ar[i] = newimage();
    }
    ques = newimage();
    water = newimage();
    moguimage = newimage();
    prin=newimage();
    mon= newimage();
    bg = newimage();
    di = newimage();
    love = newimage();
    mushroom = newimage();

    getimage(mushroom,"c\\underground\\mon1.png");
    getimage(monster[0],"c\\ground1\\mons.png");
    getimage(monster[1],"c\\ground1\\mons2.png");
    getimage(tor[0],"c\\ground1\\torr.png");
    getimage(tor[1],"c\\ground1\\torl.png");
    getimage(ar[0],"c\\ground1\\al.png");
    getimage(ar[1],"c\\ground1\\au.png");
    getimage(ar[2],"c\\ground1\\ad.png");
    getimage(mapimage,"c\\ground1\\map1.jpg");
   /* getimage(lunyiboy[0],"c\\underground\\lunyi.png");
    getimage(lunyiboy[1],"c\\underground\\lunyi2.png");*/
    getimage(lunyiboy[0],"c\\underground\\lunyi6.png");
    getimage(lunyiboy[1],"c\\underground\\lunyi61.png");
    getimage(prin,"c\\ground1\\prin.png");
    getimage(love,"c\\ground1\\over.png");
    getimage(map1image[0],"c\\underground\\map1.0.png");
    getimage(map1image[1],"c\\underground\\map1.1.png");
    getimage(map1image[2],"c\\underground\\map1.3.png");
    getimage(map1image[3],"c\\underground\\map1.2.png");
    getimage(map2image[0],"c\\underground\\map2.0.png");
    getimage(map2image[1],"c\\underground\\map2.1.png");
    getimage(map2image[2],"c\\underground\\map2.3.png");
    getimage(map2image[3],"c\\underground\\map2.2.png");
    getimage(ambulen[0],"c\\underground\\m1.0.png");
    getimage(ambulen[1],"c\\underground\\m1.1.png");
    getimage(ambulen[2],"c\\underground\\m1.2.png");
    getimage(ambulen[3],"c\\underground\\m1.3.png");
    getimage(bg,"c\\underground\\bg.png");
    getimage(mari[0],"c\\ground1\\mariol.1.png");  //0 ×óÒ»
    getimage(mari[1],"c\\ground1\\mariol.2.png");  //1    ×ó¶þ
    getimage(mari[2],"c\\ground1\\marior.1.png");  //2         ÓÒÒ»
    getimage(mari[3],"c\\ground1\\marior.2.png");  //3             ÓÒ¶þ
    getimage(mari[4],"c\\ground1\\jump1.png");
    getimage(mari[5],"c\\ground1\\jumpd.png");
    getimage(mari[6],"c\\underground\\jumpdie.png");
    getimage(mari[7],"c\\underground\\jumpdiele.png");
    getimage(wal[0],"c\\ground1\\wal.jpg");
    getimage(wal[1],"c\\underground\\wal.jpg");
    getimage(wal[2],"c\\underground\\walb.png");
    getimage(wal[3],"c\\ground1\\walb.png");
    getimage(wal[4],"c\\ground1\\walo.png");
    getimage(ques,"c\\ground1\\ques.jpg");
    getimage(water,"c\\ground1\\water.png");
    getimage(moguimage,"c\\ground1\\mogu.png");
    getimage(mar[0],"c\\ground1\\mar.png");  // you
    getimage(mar[1],"c\\ground1\\mal.png");   // zuo
    getimage(mon,"c\\underground\\mon2.png");
    getimage(goldi[0],"c\\ground1\\gold.png");
    getimage(goldi[1],"c\\ground1\\goldiif.png");
    getimage(goldi[2],"c\\ground1\\goldif.png");
    getimage(goldi[3],"c\\ground1\\goldf.png");
    getimage(di,"c\\bad\\die.png");
    getimage(star[0],"c\\ground1\\starr.png");
    getimage(star[1],"c\\ground1\\starr1.png");
    getimage(star[2],"c\\ground1\\starr2.png");
    getimage(star[3],"c\\ground1\\starr4.png");
}

void init()
{
    int i;
    init_map();
    itime =0;
    init_pic();
    conting = 1;
    mario.alive =1;
    mario.victory = 0;
   if(mario.speed != 2)
      map_sign = 0;
    //lun = 0;
    am = 0;
    if(mark !=1 )
       {
           return;
       }

    mario.x=1;
    mario.y=15;
    mario.arrow = right;
    mario.high = 0;
    mario.dex =0;

    /**** 一关怪物 二关蘑菇 ***/
    if(gamelevel == 2)
    {
        monste.x = 3;
        monste.y = 3;
        monste.alive = 0;
    }
    if(gamelevel == 1)
    {
        monste.y = 11;
        monste.x = 8;
        monste.alive = 1;
        monste.arrow = right;
        monste.speed = 20;
        monste.dex = 0;
    }

    /* if(mark == 0)
     {
         mario.speed =0;
         mark ++;
     }*/

    // mario.aim=0;

    mogu.arrow = right;
    mogu.dex =0;
    /***** ground、蘑菇  under 怪物*****/
    if(gamelevel == 1)
    {
        mogu.y =6;
        mogu.x =10;
        mogu.speed =3;
    }

    if(gamelevel == 2)
    {
        mogu.y =6;
        mogu.x =8;
        mogu.speed =10;
    }

    /*** 可以撞碎的砖块 ****/
    if(gamelevel == 2)
    {
        sto[0].x = 3;
        sto[0].y = 13;
        sto[0].alive = 0;
    }
    if(gamelevel == 1)
    {
        sto[0].x = 7;
        sto[0].y = 5;
        sto[0].alive = 0;
        temp = 0;
    }


    /**** 问号 公主 *****//*** 隐藏的砖块 ***/
    if(gamelevel == 1)
    {
        qu[0].x =10;
        qu[0].y =7;      // ground  问号
        qu[0].dex =0;
        prins.x = 2;
        prins.y = 15;
        prins.alive = 1;
        prins.dex = 1;
        prins.arrow = right;
    }
    else if(gamelevel == 2)
    {
        //   qu[1].dex=1;
        qu[0].x =15;
        qu[0].y =8;     //  墙壁   under  ston
        qu[0].dex =0;
        prins.alive = 0;
    }
     sto[1].x=7;
     sto[1].y=4;
     sto[1].alive =0;  // 两关均有的隐藏砖块


    for(i=0; i<5; i++)
    {
        gold[i].y = 6;
        gold[i].x = 8+i;
        gold[i].alive = 1;
    }
    gold[5].y =2;
    gold[5].x =7;
    gold[5].alive =1;

    gold[6].x=13;
    gold[6].y=1;
    gold[6].alive =1;

    gold[7].x =3;
    gold[7].y=12;
    gold[7].alive =1;

    gold[8].x =10;
    gold[8].y =4;
    gold[8].alive =0;


    //  qu[1].x =10;
    //  qu[1].y=6;

    memccpy(map2,map,sizeof(int),sizeof(map));
}
void goback_map()
{
    memccpy(map,map2,sizeof(int),sizeof(map2));
}
void show_menu()
{
    char s[10],t[10],z[10],i[10];
    sprintf(s,"%d",score_num);
    sprintf(t,"%d",gamelevel);
    sprintf(z,"%.5d",game_score);
    sprintf(i,"%.5d",second);
    setfont(15,0,"黑体");
    if(gamelevel == 1)
        setcolor(RED);
    else if(gamelevel == 2)
        setcolor(WHITE);
    setbkmode(TRANSPARENT);
    if(gold[6].alive ==1)
        putimage_transparent(NULL,goldi[g-1],13*25,1*25,BLACK);
    else
        putimage_transparent(NULL,goldi[0],13*25,1*25,BLACK);
    outtextxy(355,28,"x");
    outtextxy(370,30,s);

    setfont(20,15,"黑体");
    outtextxy(450,20,"WORLD");
    outtextxy(150,20,"MARIO");
    outtextxy(625,20,"TIME");
    setfont(15,0,"黑体");
    char t1[] = "1 -";
    outtextxy(468,42,t1);
    outtextxy(495,42,t);
    outtextxy(165,42,z);
    outtextxy(640,42,i);

}

void DrawStart()
{
    initgraph(800,500);
    putimage_withalpha(NULL, bg, 0, 0);
}

void DrawClose()
{
    putimage(0,0,bgl);
}
/*
	功能：
		判断游戏是否过关
	返回值：
		1：过关
		2：还未过关
*/
int PassOrNot()
{
    if(map[mario.y][mario.x] == 20 ||map[mario.y][mario.x] == 21)
    {
        if(score_num >4 || mario.speed == 1)
            return 1;
        else
            return 5;
    }
    else if(mario.alive == 0)
    {
        if(mario.high == 2)
            return 4;
        else
            return 2;
    }
    else if(map_sign == 1 && mario.victory == 1)
    {
        return 3;
    }
        return 0;
}

/*
	功能：
		画过关提示
	返回值：
		1：已经画了2秒
		0：还没画够2秒
*/
int DrawNext()
{
     static float  currentTime = timeGetTime();//当前时间
     static float  lastTime = 0.0f;//持续时间
    lastTime = timeGetTime();
    if (lastTime-currentTime> 2000.0f)
    {
        return 1;
        currentTime = timeGetTime();
        lastTime = 0.0f;
    }
    putimage_withalpha(NULL, marion[1], 10, 10);
    putimage_withalpha(NULL, img, 0, 0);
    return 0;
}

/*
	功能：
		淡出画图(画面渐渐变黑)
	返回值：
		1：淡出完毕
		0：正在淡出
*/
int DrawFO()
{
    alpha+=4;
    if (alpha >= 255)
    {
        gameState = 4;
        alpha = 254;
        return 1;
    }
    putimage_alphablend(NULL, bg, 0, 0, alpha);
    return 0;
}

/*
	功能：
		淡入画图(画面渐渐变透明)
*/
void DrawFI()
{
    alpha -= 4;
    if (alpha <=0)
    {
        if(mario.alive == 1)
           {
               if(mario.victory == 0)
                gameState = 1;
               else
                gameState  = 9;

           }
        else
        {
            if(life_num >0)
             gameState = 5;
        }

        alpha = 0;
    }
    putimage_alphablend(NULL, bg, 0, 0, alpha);
}

int showmap()
{
    TIME();
    int i,j;
    k=k%4 +1;

    if(itime % 4 == 0)
    {
         g=g%4+1;
    }

    cleardevice();
    goback_map();

    for(i=0; i<8; i++)
        if(gold[i].alive == 1)
        {
            map[gold[i].y][gold[i].x] =8;
        }

    if(gamelevel == 1)
        putimage(0,0,mapimage);
    if(gamelevel == 2 && map_sign == 0)
       {
           putimage(0,0,map1image[k-1]);
           map[9][27] = 25;
           map[9][28] = 25;
           map[10][27] = 25;
           map[10][28] = 25;
           map[11][27] = 25;
           map[11][28] = 25;
           map[12][27] = 26;
           map[12][28] = 26;
           map[13][27] = 1;
           map[13][28] = 1;
       }
    else if(gamelevel == 2 && map_sign == 1)
        putimage(0,0,map2image[k-1]);

    if(prins.alive)
    {
        if(prins.dex-1 == 0)
            map[prins.y][prins.x] = 13;
        else if(prins.dex-1 == 1)
            prins.y = prins.y -3;
        else if(prins.dex-1 == 2)
            prins.y = prins.y -5;
        while(map[prins.y+1][prins.x] !=1)
            prins.y++;
        map[prins.y][prins.x] = 13;
    }
    for(i=0; i<2; i++)
    {
        if(sto[i].alive == 0)
        map[sto[i].y][sto[i].x] = 7;
    }
    if(sto[0].alive == 1)
        map[sto[0].y][sto[0].x] = 12;

    else if(sto[0].alive == 2 && gamelevel == 1)
    {
        map[sto[0].y][sto[0].x] = 14;
    }
    else if(sto[0].alive == 2 || sto[0].alive == 3 )
    {
        map[sto[0].y][sto[0].x] = 11;
    }
    else if(sto[0].alive == 4)
    {
        if(temp == 0)
        {
            gold[8].alive =1;
            temp = 1;
        }
    }

    if(monste.alive)
    {
        map[monste.y][monste.x] = 30;
    }

    if(gamelevel == 1 &&(!(mario.y >9 && mario.x >26 ||
                           mario.y >13 && mario.x > 23)))
    {
        if(mario.speed == 0)           // speed 用来标记 他吃了蘑菇没有
            map[mario.y][mario.x] =3;
        else if(mario.speed == 1)
            map[mario.y][mario.x]=6;
        else
            map[mario.y][mario.x] = 99;
    }

    else if(gamelevel == 2)
    {
        if(!(mario.y >15 &&((mario.x>15 && mario.x <19)||
                            (mario.x>19 && mario.x <27))))
        {
            if(mario.speed == 0)
                map[mario.y][mario.x] =3;
            else if(mario.speed == 1)
            map[mario.y][mario.x]=6;
            else
            map[mario.y][mario.x] = 99;
        }
        else
        {
            mario.alive = 0;
        }
    }
    if(mogu.dex == 1)
        map[mogu.y][mogu.x] =5;
    if(qu[0].dex == 0)
        map[qu[0].y][qu[0].x] = 4;
    if(qu[0].dex == 1)
    {
        map[qu[0].y][qu[0].x] = 12;
    }
    if(gold[8].alive == 1)
        map[gold[8].y][gold[8].x] =11;
    /***  地图的显示  ***/
    for(i=0; i<18; i++)
    {
        for(j=0; j<30; j++)
        {
            if(map[i][j] == 2 || map[i][j] == 12)
            {
                if(gamelevel == 2)
                    putimage(j*25,i*25,wal[1]);
                if(gamelevel == 1)
                    putimage(j*25,i*25,wal[0]);
            }

            if(map[i][j] == 8)
            {
                putimage_transparent(NULL,goldi[g-1],j*25,i*25,BLACK);

            }
            if(map[i][j]== 99)
            {
              if(mario.arrow == right )
                    putimage_transparent(NULL,lunyiboy[0],j*25,i*25,BLACK);
              if(mario.arrow == left)
                    putimage_transparent(NULL,lunyiboy[1],j*25,i*25,BLACK);
            }
            if(map[i][j] == 30)
            {
                if(gamelevel == 1)
                   {
                       if(monste.arrow == right)
                       {
                           if(monste.dex == 0)
                            putimage_transparent(NULL,monster[0],j*25,i*25,BLACK); // 怪物
                           else
                            putimage_transparent(NULL,tor[0],j*25,i*25,BLACK); // 怪物
                       }
                       else
                       {
                           if(monste.dex == 0)
                           putimage_transparent(NULL,monster[1],j*25,i*25,BLACK);
                           else
                           putimage_transparent(NULL,tor[1],j*25,i*25,BLACK); // 怪物
                       }

                   }
                else
                    putimage_transparent(NULL,mushroom,j*25,i*25,BLACK);    //蘑菇
            }
            if(map[i][j] ==11)
            {
                if( i == sto[0].y && j == sto[0].x)
                {
                    if(gamelevel == 2)
                        putimage_transparent(NULL,wal[2],j*25,i*25,BLACK);
                    else if(gamelevel ==1)
                        putimage_transparent(NULL,wal[3],j*25,i*25,BLACK);
                }
                if(gold[8].alive == 1)
                {
                    putimage_transparent(NULL,star[g-1],j*25,i*25,BLACK);
                    map[i][j] = 8;
                }
            }
            if(map[i][j]  == 14 )
            {
                putimage_transparent(NULL,wal[4],(j-1)*25,(i-1)*25,BLACK);
                map[i][j] =11;
            }
            if(map[i][j] == 3)
            {
                if(mario.high == 1)
                    putimage_transparent(NULL,mari[6],j*25,i*25,BLACK);
                else if(mario.high == 2)
                    putimage_transparent(NULL,mari[7],j*25,i*25,BLACK);
                else if(mario.arrow == right && (mario.dex ==0||mario.dex ==2))
                    putimage_transparent(NULL,mari[2],j*25,i*25,BLACK);
                else if(mario.dex == 3)
                {
                    putimage_transparent(NULL,mari[4],j*25,i*25,BLACK);
                    mario.dex =0;
                }
                else if(mario.dex == 4)
                {
                    putimage_transparent(NULL,mari[5],j*25,i*25,BLACK);
                    mario.dex = 0;
                }
                else if(mario.arrow == right && mario.dex ==1)
                    putimage_transparent(NULL,mari[3],j*25,i*25,BLACK);
                else if(mario.arrow == left && (mario.dex ==0||mario.dex ==2))
                    putimage_transparent(NULL,mari[0],j*25,i*25,BLACK);
                else  if(mario.arrow == left && mario.dex ==1)
                    putimage_transparent(NULL,mari[1],j*25,i*25,BLACK);

            }
            if(map[i][j] == 4)
            {
                if(gamelevel == 1)
                    putimage(j*25,i*25,ques);
                else if(gamelevel == 2)
                    map[i][j] =7;
            }
            if(map[i][j] == 5)
            {
                if(gamelevel == 1)
                    putimage_transparent(NULL,moguimage,j*25,i*25,BLACK);
                if(gamelevel == 2)
                    putimage_transparent(NULL,mon,j*25,i*25,BLACK);
            }
            if(map[i][j] == 6)
            {
                if(mario.arrow == right )
                    putimage_transparent(NULL,mar[0],j*25,i*25,BLACK);
                if(mario.arrow == left)
                    putimage_transparent(NULL,mar[1],j*25,i*25,BLACK);

            }
            if(map[i][j] == 13)
            {
                putimage_transparent(NULL,prin,j*25,i*25,BLACK);
            }
            if(map[i][j] == 9)
                putimage_transparent(NULL,water,j*150,i*150,BLACK);

        }
        printf("\n");
    }
    show_menu();
}
void monster_move()
{

    // if(monste.dex == 1)
     // mons.speed = 4;
      if(map[monste.y+1][monste.x] ==0 || (monste.y +1 == mario.y && monste.x == mario.x))
        {
            monste.y++;
            return;
        }
     if(monste.dex == 0)
        monste.speed = 10;
     else
        monste.speed = 5;
        if(itime % monste.speed !=0)
           return;
        if(gamelevel == 2)
            return;
        if(monste.alive == 0 )
            return;


        if(monste.arrow == right)
           {
             /*  if(map[monste.y][monste.x+1] != 1)
                monste.x++;*/
                if(monste.x+1!= 24)
                monste.x++;
               else
                monste.arrow = left;
           }
        if(monste.arrow == left)
           {
            if(map[monste.y][monste.x-1] != 1)
                monste.x --;
            if(map[monste.y][monste.x-1] ==1)
               {
                   if(monste.dex == 0)
                      monste.arrow = right;
                   else
                      monste.alive = 0;
               }
           }
}

void mogu_move()
{

    if(gamelevel ==1)
    {
        if(itime % mogu.speed !=0)
            return;
        if(mogu.dex == 0)
            return;
        if(map[mogu.y+1][mogu.x] ==0 || (mogu.y+1 == mario.y &&mogu.x == mario.x))
        {
            mogu.y++;
            return;
        }
        if(mogu.y-1 == mario.y && mogu.x == mario.x ||
                mogu.y+1 == mario.y && mogu.x == mario.x ||
                mogu.y == mario.y && mogu.x+1 == mario.x ||
                mogu.y == mario.y && mogu.x-1 == mario.x)
        {
            mogu.x = mario.x;
            mogu.y = mario.y;
            return;
        }
        if(mogu.arrow == right)
            if(map[mogu.y][mogu.x+1] != 1)
            {
                mogu.x ++;
                if(map[mogu.y][mogu.x+1] ==1 ||
                        map[mogu.y][mogu.x+1] == 20)
                    mogu.arrow = left;
            }
        if(mogu.arrow == left)
            if(map[mogu.y][mogu.x-1] != 1)
            {
                mogu.x --;
                if(map[mogu.y][mogu.x-1] ==1)
                {
                    mogu.x--;
                    showmap();
                    mogu.dex = 0;
                }
            }

    }
    else if(gamelevel ==2)
    {
        if(itime % mogu.speed !=0)
            return;
        if(mogu.dex == 0)
            return;
        if(map[mogu.y+1][mogu.x] ==0 || (mogu.y+1 == mario.y &&mogu.x == mario.x))
        {
            mogu.y++;
            return;
        }
        if(mogu.arrow == right)
           {
               if(map[mogu.y][mogu.x+1] != 2)
                mogu.x++;
                else
                mogu.arrow = left;
           }
        if(mogu.arrow == left)
           {
            if(map[mogu.y][mogu.x-1] != 2)
                mogu.x --;
            if(map[mogu.y][mogu.x-1] ==2)
                mogu.arrow = right;
           }
    }

}
void show_victo()
{
    initgraph(1024,640);
    cleardevice();
    PIMAGE vic;
    vic = newimage();
    getimage(vic,"c\\vic\\vic.jpg");
    putimage(0,0,vic);
  //  putimage(0,0,mari[0]);
}
void Drawvicto()
{
     //   show_victo();
     printf("123456");
        mciSendString(TEXT("stop back"), NULL, 0, NULL);
        sign = 5;
        mciSendString(TEXT("open music\\bg2.mp3 alias back2"), NULL, 0, NULL);	//循环播放背景音乐
        mciSendString(TEXT("play back2 repeat"), NULL, 0, NULL);
        setfillcolor(BLACK);
        bar(80,500,200,550,NULL);
        setfont(40, 0,"宋体");
        setbkmode(TRANSPARENT);
        setcolor(WHITE);
        outtextxy(100,500,"EXIT");

         while(mousemsg())      // 检测当时是否有鼠标消息
        {
            ms=getmouse();
            if(ms.x>80 && ms.x<200 && ms.y >500 && ms.y <550)
            {
                setfillcolor(LIGHTGRAY);
                bar(80,500,200,550,NULL);
                setfont(40, 0,"宋体");
                setbkmode(TRANSPARENT);
                setcolor(BLUE);
                outtextxy(100,500,"EXIT");
            }
        }
        delay_fps(60);
        ms=getmouse();
        if(ms.is_left() && ms.x>80 && ms.x<200 && ms.y >500 && ms.y <550)
        {
            gameState = 10;
        }
}
void show_die()
{
    cleardevice();
    conting = 0;
    char s[10];
    sprintf(s,"%d",life_num);
    setfont(30,0,"黑体");
    setcolor(WHITE);
    setbkmode(TRANSPARENT);
    //  putimage_transparent(NULL,di,0.8*200,0.5*200,BLACK);
    outtextxy(410,200,"x");
    outtextxy(515,200,s);
    putimage_withalpha(NULL, di, 0.8*200, 0.5*200);

}
/*
	功能：
		画过关提示
	返回值：
		1：已经画了2秒
		0：还没画够2秒
*/
int DrawDie()
{
    mciSendString(TEXT("stop back"), NULL, 0, NULL);
    sign = 5;
    static float  currentTime = timeGetTime();//当前时间
    static float  lastTime = 0.0f;//持续时间
    lastTime = timeGetTime();
    if (lastTime-currentTime> 2000.0f)
    {
        return 1;
        currentTime = timeGetTime();
        lastTime = 0.0f;
    }
    putimage_withalpha(NULL, bad1, 0.8*100, 0.5*100);

    return 0;
}
int game_control()
{
    int i;
    int t =0; //跳跃时标记有无障碍
    char arrow;
    if(conting != 0)
    {
        showmap();
        /* 继续添加一个选择:
        重新来还是怎么的*/
    }
    Sleep(30);
    if(map[mario.y+1][mario.x] == 26||
        map[mario.y+1][mario.x] == 25)
    {
            mario.x = 28;
        if(map[mario.y+1][mario.x] == 26)
        {
           mario.y++;
           mario.high = 2;
           showmap();
           Sleep(1000);
           mario.alive = 0;
        }
        else
        {

            if(te == 0)
            {
               mario.y++;
               mario.high = 1;
               Sleep(50);
               te++;
            }
            else
            {
               mario.y++;
               mario.high = 1;
               Sleep(500);
            }

        }
    }
    else if(map[mario.y+1][mario.x] == 0          ||
            (map[mario.y+1][mario.x]==4 && gamelevel == 2)||
            map[mario.y+1][mario.x] == 7          ||
            map[mario.y+1][mario.x] == 21          ||
            map[mario.y+1][mario.x] == 30  &&gamelevel == 2)
    {
        mario.y++;
        mario.dex = 4;
    }
    else if(map[mario.y+1][mario.x] == 8)
    {
        for(i=0; i<20; i++)
        {
            if(gold[i].alive == 0)
                continue;
            if(gold[i].x ==mario.x &&gold[i].y == mario.y+1)
            {
                sign = 2;
                pthread_create(&BGM,NULL,play_clickmusic,&sign);
                gold[i].alive =0;
                t = 1;
            }
            if(gold[8].x ==mario.x &&gold[8].y == mario.y+1)
            {
                sign = 2;
                pthread_create(&BGM,NULL,play_clickmusic,&sign);
                gold[8].alive =0;
                game_score = game_score +80;
                t = 1;
            }

        }
        mario.y++;
        game_score = game_score +20;
        mario.dex =4;
        score_num++;
    }

    if(gamelevel == 1 && map[mario.y+1][mario.x] == 30)
    {
        t = 1;
        sign = 7;
        pthread_create(&BGM,NULL,play_clickmusic,&sign);
        monste.dex = 1;
        monste.arrow =right;
        game_score=game_score +20;
    }

    if((mario.y == monste.y &&mario.x == monste.x )&&monste.alive == 1 )
    {
       if(gamelevel == 1)
          mario.alive = 0;
       if(gamelevel == 2)
       {
           sign = 4;
           pthread_create(&BGM,NULL,play_clickmusic,&sign);
           mario.speed = 0;
           monste.alive = 0;
       }
    }

    if(gamelevel ==2 && map[mario.y+1][mario.x] == 5)
       {
           t = 1;
           sign = 7;
           pthread_create(&BGM,NULL,play_clickmusic,&sign);
           mogu.dex =0;
       }

    if(mogu.dex ==1 && mario.y == mogu.y && mario.x == mogu.x)
    {
        if(gamelevel == 1)
        {
            sign = 4;
            pthread_create(&BGM,NULL,play_clickmusic,&sign);
            mogu.dex =0;
            mario.speed =1;
            game_score=game_score + 200;
        }
        else if(gamelevel == 2)
        {
            sign = 2;
            pthread_create(&BGM,NULL,play_clickmusic,&sign);
            t = 1;
            mario.alive =0;
            mogu.dex =0;
        }
    }
    if(kbhit())
    {
        // game_control();
        int i;
        arrow = getch();
        if(arrow == VK_LEFT)   //¼üÅÌ×ó
        {
            mario.arrow = left;
            if(map[mario.y][mario.x-1] == 0 ||
                    map[mario.y][mario.x-1] == 20 ||
                    map[mario.y][mario.x-1] == 21 ||
                    map[mario.y][mario.x -1] == 7 ||
                    map[mario.y][mario.x -1] == 30)
            {
                mario.x--;
                mario.dex = mario.dex%2+1;
            }
            else if(map[mario.y][mario.x-1] == 8)
            {

                for(i=0; i<20; i++)
                {
                    if(gold[i].alive == 0)
                        continue;
                    if(gold[i].x ==mario.x-1 &&gold[i].y == mario.y)
                    {
                        sign = 2;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                        gold[i].alive =0;
                    }
                    if(gold[8].y ==mario.y-1 &&gold[8].x == mario.x)
                    {
                        sign = 2;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                        game_score=game_score + 80;
                    }
                }
                mario.x--;
                game_score=game_score + 20;
                mario.dex = mario.dex%2+1;
                score_num++;
            }
        }
        if(arrow == VK_RIGHT)   //  you
        {
            mario. arrow = right;
            if(map[mario.y][mario.x+1] == 0 ||
                    map[mario.y][mario.x+1] == 20 ||
                    map[mario.y][mario.x+1] == 21 ||
                    map[mario.y][mario.x+1] == 13)
            {
                mario.x++;
                mario.dex = mario.dex%2+1;
            }
            else if(map[mario.y][mario.x+1] == 8)
            {

                for(i=0; i<20; i++)
                {
                    if(gold[i].alive == 0)
                        continue;
                    if(gold[i].x ==mario.x+1 &&gold[i].y == mario.y)
                    {
                        sign = 2;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                        gold[i].alive =0;
                    }
                    if(gold[8].y ==mario.y-1 &&gold[8].x == mario.x)
                    {
                        sign = 2;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                        game_score=game_score + 80;
                    }
                }
                game_score=game_score + 20;
                mario.x++;
                mario.dex = mario.dex%2+1;
                score_num++;
            }
        }
        if(arrow == VK_UP)   //shang
        {
            /***    人****/
            if(mario.speed == 0)
            {
                if(map[mario.y-1][mario.x] == 0)
                {
                    for(i=0; i<6; i++)
                    {
                        mario.y=mario.y-1;
                        mario.dex = 3;
                        showmap();
                        Sleep(20);
                        if(map[mario.y-1][mario.x] !=0)
                        {
                            if(map[mario.y-1][mario.x] == 8)
                            {
                                mario.y --;
                                mario.dex =4;
                                for(i=0; i<20; i++)
                                {
                                    if(gold[i].alive == 0)
                                        continue;
                                    if(gold[i].y ==mario.y &&gold[i].x == mario.x)
                                    {
                                        t = 1;
                                        sign = 2;
                                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                        gold[i].alive =0;
                                        game_score=game_score + 20;
                                    }
                                    if(gold[8].y ==mario.y &&gold[8].x == mario.x)
                                    {
                                        t = 1;
                                        sign = 2;
                                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                        game_score=game_score + 80;
                                    }
                                }
                                score_num++;
                            }

                            else
                            {
                                sign = 0;
                                pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                t=1;
                                mario.dex =4;
                                if(map[mario.y-1][mario.x] == 4)
                                {
                                    mogu.dex =1;
                                    qu[0].dex ++;
                                    game_score=game_score + 20;
                                    showmap();
                                }
                                else if(map[mario.y-1][mario.x] == 7)
                                {
                                    if(mario.y-1 == sto[0].y &&mario.x == sto[0].x)
                                        sto[0].alive ++ ;
                                    else if(mario.y-1 == sto[1].y &&mario.x == sto[1].x)
                                        sto[1].alive = 1;
                                    else if(mario.y-1 == qu[0].y &&mario.x == qu[0].x && gamelevel == 2)
                                       {
                                           qu[0].dex ++;
                                           mogu.dex =1;
                                       }
                                    game_score=game_score + 20;
                                    showmap();
                                }
                                else if(map[mario.y -1][mario.x ] == 12 || map[mario.y -1][mario.x ] == 11)
                                {
                                    if(mario.y-1 == sto[0].y &&mario.x == sto[0].x)
                                        sto[0].alive ++ ;
                                    else if(mario.y-1 == qu[0].y &&mario.x == qu[0].x)
                                        qu[0].dex ++;
                                    game_score=game_score + 20;
                                    showmap();
                                }

                                break;
                            }
                            //  t = 1;
                        }

                    }
                    if(t == 0)
                    {
                        sign = 0;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                    }
                    /* else if(t == 2)
                         {

                             t = 0;
                         }*/
                }
                else if(map[mario.y-1][mario.x] == 22)
                {
                    mario.y --;
                    showmap();
                    mario.victory = 1;
                }
            }
             /*****滑板车  ***/
            else if(mario.speed == 1)
            {
                if(map[mario.y-1][mario.x] == 0)
                {
                    for(i=0; i<4; i++)
                    {
                       mario.y=mario.y-1;
                        mario.dex = 3;
                        showmap();
                        Sleep(20);
                        if(map[mario.y-1][mario.x] !=0)
                        {
                            if(map[mario.y-1][mario.x] == 8)
                            {
                                mario.y --;
                                mario.dex =4;
                                for(i=0; i<20; i++)
                                {
                                    if(gold[i].alive == 0)
                                        continue;
                                    if(gold[i].y ==mario.y &&gold[i].x == mario.x)
                                    {
                                        t = 1;
                                        sign = 2;
                                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                        gold[i].alive =0;
                                        game_score=game_score + 20;
                                    }
                                    if(gold[8].y ==mario.y &&gold[8].x == mario.x)
                                    {
                                        t = 1;
                                        sign = 2;
                                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                        game_score=game_score + 80;
                                    }
                                }
                                score_num++;
                            }

                            else
                            {
                                sign = 0;
                                pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                t=1;
                                mario.dex =4;
                                if(map[mario.y-1][mario.x] == 4)
                                {
                                    mogu.dex =1;
                                    qu[0].dex ++;
                                    game_score=game_score + 20;
                                    showmap();
                                }
                                else if(map[mario.y-1][mario.x] == 7)
                                {
                                    if(mario.y-1 == sto[0].y &&mario.x == sto[0].x)
                                        sto[0].alive ++ ;
                                    else if(mario.y-1 == sto[1].y &&mario.x == sto[1].x)
                                       {
                                          sto[1].alive = 1;
                                          monste.alive = 1;
                                       }
                                    else if(mario.y-1 == qu[0].y &&mario.x == qu[0].x && gamelevel == 2)
                                       {
                                           qu[0].dex ++;
                                           mogu.dex =1;
                                       }
                                    game_score=game_score + 20;
                                    showmap();
                                }
                                else if(map[mario.y -1][mario.x ] == 12 || map[mario.y -1][mario.x ] == 11)
                                {
                                    if(mario.y-1 == sto[0].y &&mario.x == sto[0].x)
                                        sto[0].alive ++ ;
                                    else if(mario.y-1 == qu[0].y &&mario.x == qu[0].x)
                                        qu[0].dex ++;
                                    game_score=game_score + 20;
                                    showmap();
                                }

                                break;
                            }
                            //  t = 1;
                        }
                    }
                    if(t == 0)
                    {
                        sign = 0;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                    }
                    if(t == 0)
                    {
                        sign = 0;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                    }
                }
                else if(map[mario.y-1][mario.x] == 22)
                {
                    mario.y --;
                    showmap();
                    mario.victory = 1;
                }
            }
           /****  轮椅 ***/
            else
            {
                if(map[mario.y-1][mario.x] == 0)
                {
                    for(i=0; i<3; i++)
                    {
                        mario.y=mario.y-1;
                        mario.dex = 3;
                        showmap();
                        Sleep(20);
                        if(map[mario.y-1][mario.x] !=0)
                        {
                            if(map[mario.y-1][mario.x] == 8)
                            {
                                mario.y --;
                                mario.dex =4;
                                for(i=0; i<20; i++)
                                {
                                    if(gold[i].alive == 0)
                                        continue;
                                    if(gold[i].y ==mario.y &&gold[i].x == mario.x)
                                    {
                                        t = 1;
                                        sign = 2;
                                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                        gold[i].alive =0;
                                        game_score=game_score + 20;
                                    }
                                    if(gold[8].y ==mario.y &&gold[8].x == mario.x)
                                    {
                                        t = 1;
                                        sign = 2;
                                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                        game_score=game_score + 80;
                                    }
                                }
                                score_num++;
                            }

                            else
                            {
                                sign = 0;
                                pthread_create(&BGM,NULL,play_clickmusic,&sign);
                                t=1;
                                mario.dex =4;
                                if(map[mario.y-1][mario.x] == 4)
                                {
                                    mogu.dex =1;
                                    qu[0].dex ++;
                                    game_score=game_score + 20;
                                    showmap();
                                }
                                else if(map[mario.y-1][mario.x] == 7)
                                {
                                    if(mario.y-1 == sto[0].y &&mario.x == sto[0].x)
                                        sto[0].alive ++ ;
                                    else if(mario.y-1 == sto[1].y &&mario.x == sto[1].x)
                                        sto[1].alive = 1;
                                    else if(mario.y-1 == qu[0].y &&mario.x == qu[0].x && gamelevel == 2)
                                       {
                                           qu[0].dex ++;
                                           mogu.dex =1;
                                       }
                                    game_score=game_score + 20;
                                    showmap();
                                }
                                else if(map[mario.y -1][mario.x ] == 12 || map[mario.y -1][mario.x ] == 11)
                                {
                                    if(mario.y-1 == sto[0].y &&mario.x == sto[0].x)
                                        sto[0].alive ++ ;
                                    else if(mario.y-1 == qu[0].y &&mario.x == qu[0].x)
                                        qu[0].dex ++;
                                    game_score=game_score + 20;
                                    showmap();
                                }

                                break;
                            }
                            //  t = 1;
                        }
                    }
                    if(t == 0)
                    {
                        sign = 0;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                    }
                    if(t == 0)
                    {
                        sign = 0;
                        pthread_create(&BGM,NULL,play_clickmusic,&sign);
                    }
                }
                else if(map[mario.y-1][mario.x] == 22)
                {
                    mario.y --;
                    showmap();
                    mario.victory = 1;
                }
            }
        }
    }
    if(prins.alive)
        prins.y = 15;
    int tempt =0;
    tempt = PassOrNot();
    if(tempt ==1 )
    {
        sign = 1;
        pthread_create(&BGM,NULL,play_clickmusic,&sign);
        gameState = 2;
    }
    if(tempt == 2 )
    {

        sign = 3;
        pthread_create(&BGM,NULL,play_clickmusic,&sign);
        life_num -- ;
        gameState = 6;
    }
    if(tempt == 3)
    {
        sign = 1;
        pthread_create(&BGM,NULL,play_clickmusic,&sign);
        gameState = 8;
    }
    if(tempt == 4)
    {
        sign = 3;
        pthread_create(&BGM,NULL,play_clickmusic,&sign);
        gameState = 6;
    }
    if(tempt == 5)
    {
       putimage_transparent(NULL,ar[0],8*50,3*50,BLACK);
       putimage_transparent(NULL,ar[1],5*50,4*50,BLACK);
       putimage_transparent(NULL,ar[2],1*50,3*50,BLACK);
    }
}
void ai()
{
    //  PlaySound("music\\0.wav", NULL, SND_FILENAME | SND_ASYNC);//播放一个无音效音频文件，作为终止背景音乐
    mciSendString(TEXT("stop back"), NULL, 0, NULL);
    sign = 5;
    mciSendString(TEXT("open music\\end-love.mp3 alias back1"), NULL, 0, NULL);	//循环播放背景音乐
    mciSendString(TEXT("play back1 repeat"), NULL, 0, NULL);
    conting = 0;
    cleardevice();
    putimage(1,1,bg);
    ///淡入淡出
    char s[10];
    sprintf(s,"%d",life_num);
    setfont(30,0,"黑体");
    setcolor(WHITE);
    setbkmode(TRANSPARENT);
    putimage_transparent(NULL,love,0.8*200,0.2*200,BLACK);
    outtextxy(510,100,"Love-Line");
    outtextxy(550,100,s);
    gameState = 5;
    /****插入是否重来****/
}
void prins_move()
{

    if(prins.alive == 0)
        return;
    if(prins.x == mario.x-1 && prins.y-3 == mario.y &&  mario.arrow == left && prins . arrow == right && prins.dex-1 == 1)
    {
        if(conting == 1)
            showmap();
        Sleep(500);
        ai();
        return;
    }
    else if(prins.x == mario.x-1 && prins.y-5 == mario.y &&  mario.arrow == left && prins . arrow == right && prins.dex-1 == 2)
    {
        if(conting == 1)
            showmap();
        Sleep(500);
        ai();
        return;
    }
    else if(prins.x == mario.x-1 && prins.y == mario.y &&  mario.arrow == left && prins . arrow == right && prins.dex-1 == 0)
    {
        if(conting == 1)
            showmap();
        Sleep(500);
        ai();
        return;
    }
    if(itime%8!=0)
        return;
    /* if(prins.x == mario.x+1 && prins.y == mario.y && mario.arrow == right && prins . arrow == left)
     {
         ai();
         return;
     }*/
    int arrow;
    arrow = rand()%2;
    if(arrow == 0)
        if(map[prins.y][prins.x+1] ==0 )
            prins.x++;
    if(arrow == 1)
        if(map[prins.y][prins.x-1] ==0)
            prins.x--;

    if(itime%10 == 0)
    {
        prins.dex = prins.dex %3+1;
        return;
    }


}
void time()
{
    itime++;
    if(itime%10 ==0)
        game_score++;
}
void welcom()
{
    init_wel();

    int i=4,j=1;
    while(1)
    {
        putimage(0,0,wel[i-1]);
        putimage_transparent(NULL,marion[j-1],(12-j-1)*90,4*120,BLACK);
        //   putimage_transparent(NULL,mu,0.1*200,0.1*200,BLACK);
        j=j%2+1;
        //  i=i%5+1;
        setcolor(EGERGB(0xFF,0x50,0x50));
        setfont(50,50,"新宋体");

        setbkmode(TRANSPARENT);
        outtextxy(150,420,"1. one player");
        outtextxy(150,530,"2. situation");

        while(mousemsg())      // 检测当时是否有鼠标消息
        {
            ms=getmouse();
            if(ms.x>125 && ms.x<900 && ms.y >380 && ms.y <480)
            {
                /*  setbkmode(TRANSPARENT);
                  bar(125,380,900,480,NULL);*/

                putimage_transparent(NULL,starimage[0],1*80,5*80,BLACK);
                putimage_transparent(NULL,starimage[1],10*80,5*80,BLACK);
                setbkmode(TRANSPARENT);

                outtextxy(150,420,"1. one player");
            }
            if(ms.x>125 && ms.x<900 && ms.y >500 && ms.y <600)
            {
                /* setbkmode(TRANSPARENT);
                 bar(125,500,900,600,NULL);*/
                putimage_transparent(NULL,starimage[0],1*80,6.5*80,BLACK);
                putimage_transparent(NULL,starimage[1],8*80,6.5*80,BLACK);
                setbkmode(TRANSPARENT);
                outtextxy(150,530,"2. situation");
            }
            /* if((int)ms.is_left() && ms.is_down())
             {
                 if(ms.x>125 && ms.x<900 && ms.y >380 && ms.y <480)
                     game_star();
                 if(ms.x>125 && ms.x<900 && ms.y >500 && ms.y <600)
                 /  ...;
             }*/
        }
        delay_fps(60);
        ms=getmouse();
        if(ms.is_left() && ms.x>125 && ms.x<900 && ms.y >380 && ms.y <480)
        {
            /* setbkmode(TRANSPARENT);
             bar(125,380,900,480,NULL);*/
            gameState = 3;
            break;
        }
        if(ms.is_left() && ms.x>125 && ms.x<900 && ms.y >500 && ms.y <600)
        {
            gameState = 7;
            break;
        }
        /*   if(ms.is_left() && ms.x>27 &&ms.x <42 &&ms.y>71 &&ms.y<107)
           {
               music_control = 1;
               break;
           }
           if(ms.is_left() && ms.x>36 && ms.x<72&& ms.y>125 && ms.y <161)
           {
               music_control = 0;
               break;
           }
           if(ms.is_left() && ms.x>120 && ms.x<165&& ms.y>168 && ms.y <202)
           {

               music_num ++;
               break;
           }
        */
    }
}
int choice()
{
    if(mario.alive == 0)
    {
        int Prompt;
        Prompt= MessageBox(NULL,"Wanna try again?","surper mari",MB_YESNO);
        return Prompt;
    }
    else if(mario.alive == 1)
    {
        int Prompt;
        Prompt= MessageBox(NULL,"Happy  Ending~ ?","surper mari",MB_YESNO);
        return Prompt;
    }
}
void Drawdefeat()
{
        initgraph(600,600);
        PIMAGE defeat;
        defeat = newimage();
        getimage(defeat,"c\\bad\\die1.jpg");
        putimage(0,0,defeat);
        setfillcolor(BLACK);
        bar(80,500,200,550,NULL);
        setfont(40, 0,"宋体");
        setbkmode(TRANSPARENT);
        setcolor(WHITE);
        outtextxy(100,500,"EXIT");

         while(mousemsg())      // 检测当时是否有鼠标消息
        {
            ms=getmouse();
            if(ms.x>80 && ms.x<200 && ms.y >500 && ms.y <550)
            {
                setfillcolor(LIGHTGRAY);
                bar(80,500,200,550,NULL);
                setfont(40, 0,"宋体");
                setbkmode(TRANSPARENT);
                setcolor(BLUE);
                outtextxy(100,500,"EXIT");
            }
        }
        delay_fps(60);
        ms=getmouse();
        if(ms.is_left() && ms.x>80 && ms.x<200 && ms.y >500 && ms.y <550)
        {
            gameState = 10;
        }
}
int main()
{
    setinitmode(0);
    init();

    setcaption("super mari");
    int  tempt;
    //  welcom();
    /****游戏主循环 每秒循环60次****/


    for (; is_run(); delay_fps(60))
    {
        if(sign !=5)
        {
            mciSendString(TEXT("open music\\open5.mp3 alias back"), NULL, 0, NULL);	//循环播放背景音乐
            mciSendString(TEXT("play back repeat"), NULL, 0, NULL);
        }

        printf("%d",gameState);
        printf("mario.high=%d\nmario.speed= %d\n",mario.high,mario.speed);
        printf("PassOrNot=%d\n",PassOrNot());
        printf("monste.alive=%d\n ",monste.alive);
        printf("mario.victory=%d\n",mario.victory);
        switch (gameState)
        {
        case 0:
            welcom();
            DrawClose();
            break;
        case 1:
            /*游戏逻辑更新*/
            game_control();
            prins_move();
            /*if(kbhit()) {
                char ch = getch();
                KeyToMove(ch);
            }
            /*游戏画面更新*/

            // DrawFO();
            break;
        case 2:		//过关提示
            showmap();
            if (DrawNext() == 1)
                gameState = 3;
            break;
        case 3:		//淡出
            if (mark == 0)
                DrawStart();
            else
                showmap();
            if (DrawFO() == 1)
            {
                if(mario.high != 2)
                    gamelevel++;
                mark = 1;
                init();
                //ReadFiles(nowLevel);
            };
            break;
        case 4:		//淡入
            if(mario.victory == 1)
                show_victo();
            else if(life_num == 0)
            {
                sign = 5;
                mciSendString(TEXT("stop back"), NULL, 0, NULL);
                Drawdefeat();
            }
            else
            showmap();
            DrawFI();
            break;

        case 5:
            tempt=choice();
            if(mario.alive == 0)
            {
                if(tempt== 6)
                {
                    mark = 0;
                    sign = 4;
                    gameState = 3;
                    mario.alive = 1;
                    mario.speed = 0;
                    gamelevel = 0;
                    map_sign = 0;
                }
                else if(tempt== 7)
                    return 0;
            }
            else if(mario.alive == 1)
            {
                if(tempt== 6)
                    return 0;
                else if(tempt== 7)
                {
                    mciSendString(TEXT("stop back1"), NULL, 0, NULL);
                    sign = 4;
                    showmap();
                    gameState = 3;
                    gamelevel = 0;
                }
            }
            break;

        case 6:
            if(mario.high == 2)
                  {
                      sign = 5;
                      mciSendString(TEXT("stop back"), NULL, 0, NULL);
                      putimage(0,0,ambulen[am]);
                      Sleep(1000);
                      am++;
                      gameState = 6;
                      if(am== 4)
                     {
                        gameState = 3;
                        map_sign = 1;
                        mario.speed = 2;
                        sign = 1;
                      }
                  }
            else
            {
                show_die();
               if(life_num == 0)
                   {
                      if(DrawDie()==1)
                   {
                      gameState = 4;
                   }
                   }
               else
               {
                  if(DrawDie()==1)
                   {
                      gameState = 5;
                   }
               }
            }
            break;

        case 7:
            show_situation();
        case 8:
            showmap();
            if (DrawFO() == 1);
           /* {
                //ReadFiles(nowLevel);
            };*/
            break;
        case 9:
            Drawvicto();
            break;
        case 10:
            exit(0);
            //break
        default:
            break;

        }
        time();
        mogu_move();
        monster_move();

    }
    closegraph();

}





