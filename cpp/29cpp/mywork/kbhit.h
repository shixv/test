#ifndef KBHIT_H_
#define KBHIT_H_
#include <termios.h>
#include <term.h>
#include <unistd.h>
class Kbhit
{
    private:
        struct termios initial_settings;
        struct termios new_settings;
        int peek_character;
        static Kbhit* instance;
        Kbhit(){
            init_keyboard();
            peek_character=-1;
        }
        void init_keyboard(){
            tcgetattr(0,&initial_settings);
            new_settings=initial_settings;
            new_settings.c_lflag&=~ICANON;
            new_settings.c_lflag&=~ECHO;
            new_settings.c_lflag&=~ISIG;
            new_settings.c_cc[VMIN]=1;
            new_settings.c_cc[VTIME]=0;
            tcsetattr(0,TCSANOW,&new_settings);
        }
        void close_keyboard(){
            tcsetattr(0,TCSANOW,&initial_settings);
        }
        int kbhit()
        {
            char ch;
            int nread;
            if(peek_character!=-1)
                return 1;
            new_settings.c_cc[VMIN]=0;
            tcsetattr(0,TCSANOW,&new_settings);
            nread=read(0,&ch,1);
            new_settings.c_cc[VMIN]=1;
            tcsetattr(0,TCSANOW,&new_settings);

            if(nread==1){
                peek_character=ch;
                return 1;
            }
            return 0;
        }
        char readch()
        {
            char ch;
            if(peek_character!=-1){
                ch=peek_character;
                peek_character=-1;
                return ch;
            }
            read(0,&ch,1);
            return ch;
        }
    public:
        ~Kbhit(){
            close_keyboard();
        }

        bool operator()(char& ch,int duration){
            bool ret;
            usleep(duration*1000000);
            if((ret=kbhit()))ch=readch();
            return ret;
        }
        bool operator()(char& ch,double duration){
            bool ret;
            usleep(duration*1000000);
            if((ret=kbhit()))ch=readch();
            return ret;
        }
        static Kbhit& Instance(){return *instance;}
};
Kbhit* Kbhit::instance=new Kbhit;
Kbhit kbhit=Kbhit::Instance();
#endif
