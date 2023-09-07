#include <architecture/system_model/sim_model.h>
#include <architecture/system_model/sys_process.h>
#include <architecture/system_model/sys_model_task.h>

#include "./include/cppModuleTemplate.h"

#include <iostream>

int main(int argc, char* argv[])
{
    SimModel scSim;
    
    // create processes
    SysProcess dynProcess("dynamicsProcess");
    scSim.addNewProcess(&dynProcess);

    // create tasks
    SysModelTask dynTask(1000000000); // dynamics task
    dynTask.TaskName = "dynamicsTask";
    dynProcess.addNewTask(&dynTask);    // add dyn task into dynamics process

    // create modules
    CppModuleTemplate mod1;
    mod1.ModelTag = "cppModule1";

    // add module to task
    dynTask.AddNewObject(&mod1);

    // connect messages
    mod1.dataInMsg.subscribeTo(&mod1.dataOutMsg);

    // recorder
    Recorder<CModuleTemplateMsgPayload> msgRec = mod1.dataOutMsg.recorder();
    dynTask.AddNewObject(&msgRec);
    
    Recorder<CModuleTemplateMsgPayload> msgRec2 = mod1.dataOutMsg.recorder(20000000000);
    dynTask.AddNewObject(&msgRec2);

    // initialize simulation
    // scSim.selfInitSimulation();  // <------------------------ weird, it cause program hold

    // // configure a simulation stop time and execute the simulation run
    scSim.StepUntilStop(60000000000, 1);

    // std::cout << "bsk-3 program end" << std::endl;
    return 0;
}