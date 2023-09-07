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
    SysModelTask dynTask(5000000000); // dynamics task
    dynTask.TaskName = "dynamicsTask";
    dynProcess.addNewTask(&dynTask);    // add dyn task into dynamics process

    // create modules
    CppModuleTemplate mod1;
    mod1.ModelTag = "cppModule1";

    CppModuleTemplate mod2;
    mod2.ModelTag = "cppModule2";

    CppModuleTemplate mod3;
    mod3.ModelTag = "cppModule3";

    dynTask.AddNewObject(&mod1); //
    dynTask.AddNewObject(&mod2, 10);
    dynTask.AddNewObject(&mod3, 5);
    
    // initialize simulation
    // scSim.selfInitSimulation();  // <------------------------ weird, it cause program hold

    // configure a simulation stop time and execute the simulation run
    scSim.StepUntilStop(20000000000, 1);

    std::cout << "bsk-2 program end" << std::endl;
    return 0;
}