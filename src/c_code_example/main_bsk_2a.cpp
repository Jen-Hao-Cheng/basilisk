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

    // // mmodifed dummy value
    // mod1.dummy = -10;
    // std::cout << mod1.dummy << std::endl;
    
    // initialize simulation
    // scSim.selfInitSimulation();  // <------------------------ weird, it cause program hold
    std::cout << mod1.dummy << std::endl;

    // configure a simulation stop time and execute the simulation run
    scSim.SingleStepProcesses();
    std::cout << mod1.dummy << std::endl;

    std::cout << "bsk-2a program end" << std::endl;
    return 0;
}