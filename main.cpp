#include "object.hpp"
#include "PictureManager.hpp"
#include "RobotManager.hpp"

int main(int argC, char *argV[]){
    bool skip=false;
	RobotManager manager;
    PictureManager camera;
    camera.init(BLUE);
    
    if (argC>1){
        if (strcmp(argV[1], "-computer")==0) {
            skip=true;
        }
    }
    
    if (!skip) manager.initSerial();
    while(true){
        camera.refresh(BALL);
        if (camera.isPall) {
            camera.where(BALL);
            switch (camera.dir) {
                case FORWARD:
                    if (!skip) manager.moveRobot(0, 20, 0);
                    else std::cout << "forward" << std::endl;
                    break;
                case LEFT:
                    if (!skip) manager.moveRobot(0, 0, -10);
                    else std::cout << "left" << std::endl;
                    break;
                case RIGHT:
                    if (!skip) manager.moveRobot(0, 0, 10);
                    else std::cout << "right" << std::endl;
                    break;
                case STOP:
                    if (!skip) manager.moveRobot(0, 0, 0);
                    else std::cout << "no movement" << std::endl;
                    break; //ajutine loop värava jaoks? :D that is if this even works harhar
                    
            }
        }
        else{
            if (!skip) manager.moveRobot(0, 0, -10);
            else std::cout << "left/search" << std::endl;
        }
    }
    return 0;
}
