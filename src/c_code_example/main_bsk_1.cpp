#include <architecture/system_model/sim_model.h>
#include <architecture/system_model/sys_process.h>
#include <architecture/system_model/sys_model_task.h>

#include <iostream>

int main(int argc, char* argv[])
{
    SimModel scSim;
    
    // create processes
    SysProcess dynProcess("dynamicsProcess");
    scSim.addNewProcess(&dynProcess);

    SysProcess fswProcess("fswProcess"); // flight software process (fsw)
    scSim.addNewProcess(&fswProcess);

    // create tasks
    SysModelTask dynTask(5000000000); // dynamics task
    dynTask.TaskName = "dynamicsTask";
    dynProcess.addNewTask(&dynTask);    // add dyn task into dynamics process
    
    SysModelTask sensorTask(10000000000); // sensor task
    sensorTask.TaskName = "sensorTask";
    dynProcess.addNewTask(&sensorTask); // add sensor task into dynamics process

    SysModelTask fswTask(10000000000); // fsw task
    fswTask.TaskName = "fswTask";
    fswProcess.addNewTask(&fswTask);    // add fsw task into fsw process

    // initialize simulation
    // scSim.selfInitSimulation();  // <------------------------ weird, it cause program hold

    // configure a simulation stop time and execute the simulation run
    scSim.StepUntilStop(20000000000, 1);

    std::cout << "bsk-1 program end" << std::endl;
    return 0;
}