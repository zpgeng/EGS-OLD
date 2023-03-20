var NAVTREE =
[
  [ "StarPU Handbook", "index.html", [
    [ "Introduction", "index.html", [
      [ "Motivation", "index.html#Motivation", null ],
      [ "StarPU in a Nutshell", "index.html#StarPUInANutshell", [
        [ "Codelet and Tasks", "index.html#CodeletAndTasks", null ],
        [ "StarPU Data Management Library", "index.html#StarPUDataManagementLibrary", null ]
      ] ],
      [ "Application Taskification", "index.html#ApplicationTaskification", null ],
      [ "Glossary", "index.html#Glossary", null ],
      [ "Research Papers", "index.html#ResearchPapers", null ],
      [ "StarPU Applications", "index.html#StarPUApplications", null ],
      [ "Further Reading", "index.html#FurtherReading", null ]
    ] ],
    [ "Building and Installing StarPU", "BuildingAndInstallingStarPU.html", [
      [ "Installing a Binary Package", "BuildingAndInstallingStarPU.html#InstallingABinaryPackage", null ],
      [ "Installing from Source", "BuildingAndInstallingStarPU.html#InstallingFromSource", [
        [ "Optional Dependencies", "BuildingAndInstallingStarPU.html#OptionalDependencies", null ],
        [ "Getting Sources", "BuildingAndInstallingStarPU.html#GettingSources", null ],
        [ "Configuring StarPU", "BuildingAndInstallingStarPU.html#ConfiguringStarPU", null ],
        [ "Building StarPU", "BuildingAndInstallingStarPU.html#BuildingStarPU", null ],
        [ "Installing StarPU", "BuildingAndInstallingStarPU.html#InstallingStarPU", null ]
      ] ],
      [ "Setting up Your Own Code", "BuildingAndInstallingStarPU.html#SettingUpYourOwnCode", [
        [ "Setting Flags for Compiling, Linking and Running Applications", "BuildingAndInstallingStarPU.html#SettingFlagsForCompilingLinkingAndRunningApplications", null ],
        [ "Integrating StarPU in a Build System", "BuildingAndInstallingStarPU.html#IntegratingStarPUInABuildSystem", [
          [ "Integrating StarPU in a Make Build System", "BuildingAndInstallingStarPU.html#StarPUInMake", null ],
          [ "Integrating StarPU in a CMake Build System", "BuildingAndInstallingStarPU.html#StarPUInCMake", null ]
        ] ],
        [ "Running a Basic StarPU Application", "BuildingAndInstallingStarPU.html#RunningABasicStarPUApplication", null ],
        [ "Running a Basic StarPU Application on Microsoft Visual C", "BuildingAndInstallingStarPU.html#RunningABasicStarPUApplicationOnMicrosoft", null ],
        [ "Kernel Threads Started by StarPU", "BuildingAndInstallingStarPU.html#KernelThreadsStartedByStarPU", null ],
        [ "Enabling OpenCL", "BuildingAndInstallingStarPU.html#EnablingOpenCL", null ]
      ] ],
      [ "Benchmarking StarPU", "BuildingAndInstallingStarPU.html#BenchmarkingStarPU", [
        [ "Task Size Overhead", "BuildingAndInstallingStarPU.html#TaskSizeOverhead", null ],
        [ "Data Transfer Latency", "BuildingAndInstallingStarPU.html#DataTransferLatency", null ],
        [ "Matrix-Matrix Multiplication", "BuildingAndInstallingStarPU.html#MatrixMatrixMultiplication", null ],
        [ "Cholesky Factorization", "BuildingAndInstallingStarPU.html#CholeskyFactorization", null ],
        [ "LU Factorization", "BuildingAndInstallingStarPU.html#LUFactorization", null ],
        [ "Simulated Benchmarks", "BuildingAndInstallingStarPU.html#SimulatedBenchmarks", null ]
      ] ]
    ] ],
    [ "Basic Examples", "BasicExamples.html", [
      [ "Hello World", "BasicExamples.html#HelloWorldUsingStarPUAPI", [
        [ "Required Headers", "BasicExamples.html#RequiredHeaders", null ],
        [ "Defining A Codelet", "BasicExamples.html#DefiningACodelet", null ],
        [ "Submitting A Task", "BasicExamples.html#SubmittingATask", null ],
        [ "Execution Of Hello World", "BasicExamples.html#ExecutionOfHelloWorld", null ],
        [ "Passing Arguments To The Codelet", "BasicExamples.html#PassingArgumentsToTheCodelet", null ],
        [ "Defining A Callback", "BasicExamples.html#DefiningACallback", null ],
        [ "Where To Execute A Codelet", "BasicExamples.html#WhereToExecuteACodelet", null ]
      ] ],
      [ "Vector Scaling", "BasicExamples.html#VectorScalingUsingStarPUAPI", [
        [ "Source Code of Vector Scaling", "BasicExamples.html#SourceCodeOfVectorScaling", null ],
        [ "Execution of Vector Scaling", "BasicExamples.html#ExecutionOfVectorScaling", null ]
      ] ],
      [ "Vector Scaling on an Hybrid CPU/GPU Machine", "BasicExamples.html#VectorScalingOnAnHybridCPUGPUMachine", [
        [ "Definition of the CUDA Kernel", "BasicExamples.html#DefinitionOfTheCUDAKernel", null ],
        [ "Definition of the OpenCL Kernel", "BasicExamples.html#DefinitionOfTheOpenCLKernel", null ],
        [ "Definition of the Main Code", "BasicExamples.html#DefinitionOfTheMainCode", null ],
        [ "Execution of Hybrid Vector Scaling", "BasicExamples.html#ExecutionOfHybridVectorScaling", null ]
      ] ]
    ] ],
    [ "Advanced Examples", "AdvancedExamples.html", null ],
    [ "Check List When Performance Are Not There", "CheckListWhenPerformanceAreNotThere.html", [
      [ "Check Task Size", "CheckListWhenPerformanceAreNotThere.html#CheckTaskSize", null ],
      [ "Configuration Which May Improve Performance", "CheckListWhenPerformanceAreNotThere.html#ConfigurationImprovePerformance", null ],
      [ "Data Related Features Which May Improve Performance", "CheckListWhenPerformanceAreNotThere.html#DataRelatedFeaturesToImprovePerformance", null ],
      [ "Task Related Features Which May Improve Performance", "CheckListWhenPerformanceAreNotThere.html#TaskRelatedFeaturesToImprovePerformance", null ],
      [ "Scheduling Related Features Which May Improve Performance", "CheckListWhenPerformanceAreNotThere.html#SchedulingRelatedFeaturesToImprovePerformance", null ],
      [ "CUDA-specific Optimizations", "CheckListWhenPerformanceAreNotThere.html#CUDA-specificOptimizations", null ],
      [ "OpenCL-specific Optimizations", "CheckListWhenPerformanceAreNotThere.html#OpenCL-specificOptimizations", null ],
      [ "Detecting Stuck Conditions", "CheckListWhenPerformanceAreNotThere.html#DetectionStuckConditions", null ],
      [ "How to Limit Memory Used By StarPU And Cache Buffer Allocations", "CheckListWhenPerformanceAreNotThere.html#HowToLimitMemoryPerNode", null ],
      [ "How To Reduce The Memory Footprint Of Internal Data Structures", "CheckListWhenPerformanceAreNotThere.html#HowToReduceTheMemoryFootprintOfInternalDataStructures", null ],
      [ "How To Reuse Memory", "CheckListWhenPerformanceAreNotThere.html#HowtoReuseMemory", null ],
      [ "Performance Model Calibration", "CheckListWhenPerformanceAreNotThere.html#PerformanceModelCalibration", null ],
      [ "Profiling", "CheckListWhenPerformanceAreNotThere.html#Profiling", null ],
      [ "Overhead Profiling", "CheckListWhenPerformanceAreNotThere.html#OverheadProfiling", null ]
    ] ],
    [ "Tasks In StarPU", "TasksInStarPU.html", [
      [ "Task Granularity", "TasksInStarPU.html#TaskGranularity", null ],
      [ "Task Submission", "TasksInStarPU.html#TaskSubmission", null ],
      [ "Task Priorities", "TasksInStarPU.html#TaskPriorities", null ],
      [ "Task Dependencies", "TasksInStarPU.html#TaskDependencies", [
        [ "Sequential Consistency", "TasksInStarPU.html#SequentialConsistency", null ],
        [ "Tasks And Tags Dependencies", "TasksInStarPU.html#TasksAndTagsDependencies", null ]
      ] ],
      [ "Setting Many Data Handles For a Task", "TasksInStarPU.html#SettingManyDataHandlesForATask", null ],
      [ "Setting a Variable Number Of Data Handles For a Task", "TasksInStarPU.html#SettingVariableDataHandlesForATask", null ],
      [ "Using Multiple Implementations Of A Codelet", "TasksInStarPU.html#UsingMultipleImplementationsOfACodelet", null ],
      [ "Enabling Implementation According To Capabilities", "TasksInStarPU.html#EnablingImplementationAccordingToCapabilities", null ],
      [ "Insert Task Utility", "TasksInStarPU.html#InsertTaskUtility", null ],
      [ "Getting Task Children", "TasksInStarPU.html#GettingTaskChildren", null ],
      [ "Parallel Tasks", "TasksInStarPU.html#ParallelTasks", [
        [ "Fork-mode Parallel Tasks", "TasksInStarPU.html#Fork-modeParallelTasks", null ],
        [ "SPMD-mode Parallel Tasks", "TasksInStarPU.html#SPMD-modeParallelTasks", null ],
        [ "Parallel Tasks Performance", "TasksInStarPU.html#ParallelTasksPerformance", null ],
        [ "Combined Workers", "TasksInStarPU.html#CombinedWorkers", null ],
        [ "Concurrent Parallel Tasks", "TasksInStarPU.html#ConcurrentParallelTasks", null ],
        [ "Synchronization Tasks", "TasksInStarPU.html#SynchronizationTasks", null ]
      ] ]
    ] ],
    [ "Data Management", "DataManagement.html", [
      [ "Data Interface", "DataManagement.html#DataInterface", [
        [ "Variable Data Interface", "DataManagement.html#VariableDataInterface", null ],
        [ "Vector Data Interface", "DataManagement.html#VectorDataInterface", null ],
        [ "Matrix Data Interface", "DataManagement.html#MatrixDataInterface", null ],
        [ "Block Data Interface", "DataManagement.html#BlockDataInterface", null ],
        [ "BCSR Data Interface", "DataManagement.html#BCSRDataInterface", null ],
        [ "CSR Data Interface", "DataManagement.html#CSRDataInterface", null ],
        [ "Data Interface with Variable Size", "DataManagement.html#VariableSizeDataInterface", null ]
      ] ],
      [ "Data Management", "DataManagement.html#DataManagement", null ],
      [ "Data Prefetch", "DataManagement.html#DataPrefetch", null ],
      [ "Partitioning Data", "DataManagement.html#PartitioningData", null ],
      [ "Asynchronous Partitioning", "DataManagement.html#AsynchronousPartitioning", null ],
      [ "Manual Partitioning", "DataManagement.html#ManualPartitioning", null ],
      [ "Handles data buffer pointers", "DataManagement.html#DataPointers", null ],
      [ "Defining A New Data Filter", "DataManagement.html#DefiningANewDataFilter", null ],
      [ "Data Reduction", "DataManagement.html#DataReduction", null ],
      [ "Commute Data Access", "DataManagement.html#DataCommute", null ],
      [ "Concurrent Data Accesses", "DataManagement.html#ConcurrentDataAccess", null ],
      [ "Temporary Buffers", "DataManagement.html#TemporaryBuffers", [
        [ "Temporary Data", "DataManagement.html#TemporaryData", null ],
        [ "Scratch Data", "DataManagement.html#ScratchData", null ]
      ] ],
      [ "The Multiformat Interface", "DataManagement.html#TheMultiformatInterface", null ],
      [ "Defining A New Data Interface", "DataManagement.html#DefiningANewDataInterface", [
        [ "Data registration", "DataManagement.html#DefiningANewDataInterface_registration", null ],
        [ "Data allocation", "DataManagement.html#DefiningANewDataInterface_allocation", null ],
        [ "Data copy", "DataManagement.html#DefiningANewDataInterface_copy", null ],
        [ "Data pack/unpack", "DataManagement.html#DefiningANewDataInterface_pack", null ]
      ] ],
      [ "Specifying A Target Node For Task Data", "DataManagement.html#SpecifyingATargetNode", null ]
    ] ],
    [ "Scheduling", "Scheduling.html", [
      [ "Task Scheduling Policies", "Scheduling.html#TaskSchedulingPolicy", [
        [ "Non Performance Modelling Policies", "Scheduling.html#NonPerformanceModelingPolicies", null ],
        [ "Performance Model-Based Task Scheduling Policies", "Scheduling.html#DMTaskSchedulingPolicy", null ],
        [ "Modularized Schedulers", "Scheduling.html#ExistingModularizedSchedulers", null ]
      ] ],
      [ "Task Distribution Vs Data Transfer", "Scheduling.html#TaskDistributionVsDataTransfer", null ],
      [ "Energy-based Scheduling", "Scheduling.html#Energy-basedScheduling", null ],
      [ "Static Scheduling", "Scheduling.html#StaticScheduling", null ],
      [ "Heteroprio", "Scheduling.html#Configuring", null ]
    ] ],
    [ "Scheduling Contexts", "SchedulingContexts.html", [
      [ "General Ideas", "SchedulingContexts.html#ContextGeneralIdeas", null ],
      [ "Creating A Context", "SchedulingContexts.html#CreatingAContext", [
        [ "Creating A Context With The Default Behavior", "SchedulingContexts.html#CreatingAContextWithTheDefaultBehavior", null ]
      ] ],
      [ "Creating A Context To Partition a GPU", "SchedulingContexts.html#CreatingAGPUContext", null ],
      [ "Modifying A Context", "SchedulingContexts.html#ModifyingAContext", null ],
      [ "Submitting Tasks To A Context", "SchedulingContexts.html#SubmittingTasksToAContext", null ],
      [ "Deleting A Context", "SchedulingContexts.html#DeletingAContext", null ],
      [ "Emptying A Context", "SchedulingContexts.html#EmptyingAContext", null ]
    ] ],
    [ "Scheduling Context Hypervisor", "SchedulingContextHypervisor.html", [
      [ "What Is The Hypervisor", "SchedulingContextHypervisor.html#WhatIsTheHypervisor", null ],
      [ "Start the Hypervisor", "SchedulingContextHypervisor.html#StartTheHypervisor", null ],
      [ "Interrogate The Runtime", "SchedulingContextHypervisor.html#InterrogateTheRuntime", null ],
      [ "Trigger the Hypervisor", "SchedulingContextHypervisor.html#TriggerTheHypervisor", null ],
      [ "Resizing Strategies", "SchedulingContextHypervisor.html#ResizingStrategies", null ],
      [ "Defining A New Hypervisor Policy", "SchedulingContextHypervisor.html#DefiningANewHypervisorPolicy", null ]
    ] ],
    [ "How To Define A New Scheduling Policy", "HowToDefineANewSchedulingPolicy.html", [
      [ "Introduction", "HowToDefineANewSchedulingPolicy.html#NewSchedulingPolicy_Introduction", null ],
      [ "Helper functions for defining a scheduling policy (Basic or modular)", "HowToDefineANewSchedulingPolicy.html#SchedulingHelpers", null ],
      [ "Defining A New Basic Scheduling Policy", "HowToDefineANewSchedulingPolicy.html#DefiningANewBasicSchedulingPolicy", null ],
      [ "Defining A New Modular Scheduling Policy", "HowToDefineANewSchedulingPolicy.html#DefiningANewModularSchedulingPolicy", [
        [ "Interface", "HowToDefineANewSchedulingPolicy.html#Interface", null ],
        [ "Building a Modularized Scheduler", "HowToDefineANewSchedulingPolicy.html#BuildAModularizedScheduler", [
          [ "Pre-implemented Components", "HowToDefineANewSchedulingPolicy.html#PreImplementedComponents", null ],
          [ "Progression And Validation Rules", "HowToDefineANewSchedulingPolicy.html#ProgressionAndValidationRules", null ],
          [ "Locking in modularized schedulers", "HowToDefineANewSchedulingPolicy.html#ModularizedSchedulerLocking", null ],
          [ "Implementing a Modularized Scheduler", "HowToDefineANewSchedulingPolicy.html#ImplementAModularizedScheduler", null ]
        ] ],
        [ "Management of parallel task", "HowToDefineANewSchedulingPolicy.html#ModularizedSchedulersAndParallelTasks", null ],
        [ "Writing a Scheduling Component", "HowToDefineANewSchedulingPolicy.html#WriteASchedulingComponent", [
          [ "Generic Scheduling Component", "HowToDefineANewSchedulingPolicy.html#GenericSchedulingComponent", null ],
          [ "Instantiation : Redefining the Interface", "HowToDefineANewSchedulingPolicy.html#InstantiationRedefineInterface", null ],
          [ "Detailed Progression and Validation Rules", "HowToDefineANewSchedulingPolicy.html#DetailedProgressionAndValidationRules", null ]
        ] ]
      ] ],
      [ "Graph-based Scheduling", "HowToDefineANewSchedulingPolicy.html#GraphScheduling", null ],
      [ "Debugging Scheduling", "HowToDefineANewSchedulingPolicy.html#DebuggingScheduling", null ]
    ] ],
    [ "Debugging Tools", "DebuggingTools.html", [
      [ "TroubleShooting In General", "DebuggingTools.html#DebuggingInGeneral", null ],
      [ "Using The Gdb Debugger", "DebuggingTools.html#UsingGdb", null ],
      [ "Using Other Debugging Tools", "DebuggingTools.html#UsingOtherDebugger", null ],
      [ "Using The Temanejo Task Debugger", "DebuggingTools.html#UsingTheTemanejoTaskDebugger", null ]
    ] ],
    [ "Online Performance Tools", "OnlinePerformanceTools.html", [
      [ "On-line Performance Feedback", "OnlinePerformanceTools.html#On-linePerformanceFeedback", [
        [ "Enabling On-line Performance Monitoring", "OnlinePerformanceTools.html#EnablingOn-linePerformanceMonitoring", null ],
        [ "Per-task Feedback", "OnlinePerformanceTools.html#Per-taskFeedback", null ],
        [ "Per-codelet Feedback", "OnlinePerformanceTools.html#Per-codeletFeedback", null ],
        [ "Per-worker Feedback", "OnlinePerformanceTools.html#Per-workerFeedback", null ],
        [ "Bus-related Feedback", "OnlinePerformanceTools.html#Bus-relatedFeedback", null ],
        [ "MPI-related Feedback", "OnlinePerformanceTools.html#MPI-relatedFeedback", null ]
      ] ],
      [ "Task And Worker Profiling", "OnlinePerformanceTools.html#TaskAndWorkerProfiling", null ],
      [ "Performance Model Example", "OnlinePerformanceTools.html#PerformanceModelExample", null ]
    ] ],
    [ "Offline Performance Tools", "OfflinePerformanceTools.html", [
      [ "Off-line Performance Feedback", "OfflinePerformanceTools.html#Off-linePerformanceFeedback", [
        [ "Generating Traces With FxT", "OfflinePerformanceTools.html#GeneratingTracesWithFxT", [
          [ "Creating a Gantt Diagram", "OfflinePerformanceTools.html#CreatingAGanttDiagram", null ],
          [ "Creating a DAG With Graphviz", "OfflinePerformanceTools.html#CreatingADAGWithGraphviz", null ],
          [ "Getting Task Details", "OfflinePerformanceTools.html#TraceTaskDetails", null ],
          [ "Monitoring Activity", "OfflinePerformanceTools.html#MonitoringActivity", null ],
          [ "Getting Modular Schedular Animation", "OfflinePerformanceTools.html#Animation", null ]
        ] ],
        [ "Limiting The Scope Of The Trace", "OfflinePerformanceTools.html#LimitingScopeTrace", null ]
      ] ],
      [ "Performance Of Codelets", "OfflinePerformanceTools.html#PerformanceOfCodelets", null ],
      [ "Data trace and tasks length", "OfflinePerformanceTools.html#DataTrace", null ],
      [ "Trace Statistics", "OfflinePerformanceTools.html#TraceStatistics", null ],
      [ "Theoretical Lower Bound On Execution Time", "OfflinePerformanceTools.html#TheoreticalLowerBoundOnExecutionTime", null ],
      [ "Theoretical Lower Bound On Execution Time Example", "OfflinePerformanceTools.html#TheoreticalLowerBoundOnExecutionTimeExample", null ],
      [ "Trace visualization with StarVZ", "OfflinePerformanceTools.html#starvz", null ],
      [ "Memory Feedback", "OfflinePerformanceTools.html#MemoryFeedback", null ],
      [ "Data Statistics", "OfflinePerformanceTools.html#DataStatistics", null ]
    ] ],
    [ "Frequently Asked Questions", "FrequentlyAskedQuestions.html", [
      [ "How To Initialize A Computation Library Once For Each Worker?", "FrequentlyAskedQuestions.html#HowToInitializeAComputationLibraryOnceForEachWorker", null ],
      [ "Using The Driver API", "FrequentlyAskedQuestions.html#UsingTheDriverAPI", null ],
      [ "On-GPU Rendering", "FrequentlyAskedQuestions.html#On-GPURendering", null ],
      [ "Using StarPU With MKL 11 (Intel Composer XE 2013)", "FrequentlyAskedQuestions.html#UsingStarPUWithMKL", null ],
      [ "Thread Binding on NetBSD", "FrequentlyAskedQuestions.html#ThreadBindingOnNetBSD", null ],
      [ "StarPU permanently eats 100% of all CPUs", "FrequentlyAskedQuestions.html#StarPUEatsCPUs", null ],
      [ "Interleaving StarPU and non-StarPU code", "FrequentlyAskedQuestions.html#PauseResume", null ],
      [ "When running with CUDA or OpenCL devices, I am seeing less CPU cores", "FrequentlyAskedQuestions.html#GPUEatingCores", null ],
      [ "StarPU does not see my CUDA device", "FrequentlyAskedQuestions.html#CUDADrivers", null ],
      [ "StarPU does not see my OpenCL device", "FrequentlyAskedQuestions.html#OpenCLDrivers", null ],
      [ "I keep getting a \"Incorrect performance model file\" error", "FrequentlyAskedQuestions.html#IncorrectPerformanceModelFile", null ]
    ] ],
    [ "Out Of Core", "OutOfCore.html", [
      [ "Introduction", "OutOfCore.html#OutOfCore_Introduction", null ],
      [ "Use a new disk memory", "OutOfCore.html#UseANewDiskMemory", null ],
      [ "Data Registration", "OutOfCore.html#OOCDataRegistration", null ],
      [ "Using Wont Use", "OutOfCore.html#OOCWontUse", null ],
      [ "Examples: disk_copy", "OutOfCore.html#ExampleDiskCopy", null ],
      [ "Examples: disk_compute", "OutOfCore.html#ExampleDiskCompute", null ],
      [ "Performances", "OutOfCore.html#Performances", null ],
      [ "Feedback Figures", "OutOfCore.html#FeedBackFigures", null ],
      [ "Disk functions", "OutOfCore.html#DiskFunctions", null ]
    ] ],
    [ "MPI Support", "MPISupport.html", [
      [ "Building with MPI support", "MPISupport.html#MPIBuild", null ],
      [ "Example Used In This Documentation", "MPISupport.html#ExampleDocumentation", null ],
      [ "About Not Using The MPI Support", "MPISupport.html#NotUsingMPISupport", null ],
      [ "Simple Example", "MPISupport.html#SimpleExample", null ],
      [ "How to Initialize StarPU-MPI", "MPISupport.html#MPIInitialization", null ],
      [ "Point To Point Communication", "MPISupport.html#PointToPointCommunication", null ],
      [ "Exchanging User Defined Data Interface", "MPISupport.html#ExchangingUserDefinedDataInterface", null ],
      [ "MPI Insert Task Utility", "MPISupport.html#MPIInsertTaskUtility", null ],
      [ "Pruning MPI Task Insertion", "MPISupport.html#MPIInsertPruning", null ],
      [ "Temporary Data", "MPISupport.html#MPITemporaryData", null ],
      [ "Per-node Data", "MPISupport.html#MPIPerNodeData", null ],
      [ "Priorities", "MPISupport.html#MPIPriorities", null ],
      [ "MPI Cache Support", "MPISupport.html#MPICache", null ],
      [ "MPI Data Migration", "MPISupport.html#MPIMigration", null ],
      [ "MPI Collective Operations", "MPISupport.html#MPICollective", null ],
      [ "Make StarPU-MPI Progression Thread Execute Tasks", "MPISupport.html#MPIDriver", null ],
      [ "Debugging MPI", "MPISupport.html#MPIDebug", null ],
      [ "More MPI examples", "MPISupport.html#MPIExamples", null ],
      [ "Using the NewMadeleine communication library", "MPISupport.html#Nmad", null ],
      [ "MPI Master Slave Support", "MPISupport.html#MPIMasterSlave", null ]
    ] ],
    [ "FFT Support", "FFTSupport.html", [
      [ "Compilation", "FFTSupport.html#FFTCompilation", null ]
    ] ],
    [ "MIC Xeon Phi Support", "MICSupport.html", [
      [ "Compilation", "MICSupport.html#MICCompilation", null ],
      [ "Porting Applications To MIC Xeon Phi", "MICSupport.html#PortingApplicationsToMIC", null ],
      [ "Launching Programs", "MICSupport.html#LaunchingPrograms", null ]
    ] ],
    [ "The StarPU Native Fortran Support", "NativeFortranSupport.html", [
      [ "Implementation Details and Specificities", "NativeFortranSupport.html#NFImplementation", [
        [ "Prerequisites", "NativeFortranSupport.html#NFPrerequisites", null ],
        [ "Configuration", "NativeFortranSupport.html#NFConfiguration", null ],
        [ "Examples", "NativeFortranSupport.html#NFExamples", null ],
        [ "Compiling a Native Fortran Application", "NativeFortranSupport.html#NFAppCompile", null ]
      ] ],
      [ "Fortran Translation for Common StarPU API Idioms", "NativeFortranSupport.html#NFIdioms", null ],
      [ "Uses, Initialization and Shutdown", "NativeFortranSupport.html#NFInitExit", null ],
      [ "Fortran Flavor of StarPU's Variadic Insert_task", "NativeFortranSupport.html#NFInsertTask", null ],
      [ "Functions and Subroutines Expecting Data Structures Arguments", "NativeFortranSupport.html#NFStructs", null ],
      [ "Additional Notes about the Native Fortran Support", "NativeFortranSupport.html#NFNotes", [
        [ "Using StarPU with Older Fortran Compilers", "NativeFortranSupport.html#NFOldFortran", null ],
        [ "Valid API Mixes and Language Mixes", "NativeFortranSupport.html#NFAPIMIX", null ]
      ] ]
    ] ],
    [ "SOCL OpenCL Extensions", "SOCLOpenclExtensions.html", null ],
    [ "SimGrid Support", "SimGridSupport.html", [
      [ "Preparing Your Application For Simulation", "SimGridSupport.html#Preparing", null ],
      [ "Calibration", "SimGridSupport.html#Calibration", null ],
      [ "Simulation", "SimGridSupport.html#Simulation", null ],
      [ "Simulation On Another Machine", "SimGridSupport.html#SimulationOnAnotherMachine", null ],
      [ "Simulation Examples", "SimGridSupport.html#SimulationExamples", null ],
      [ "Simulations On Fake Machines", "SimGridSupport.html#FakeSimulations", null ],
      [ "Tweaking Simulation", "SimGridSupport.html#TweakingSimulation", null ],
      [ "MPI Applications", "SimGridSupport.html#SimulationMPIApplications", null ],
      [ "Debugging Applications", "SimGridSupport.html#SimulationDebuggingApplications", null ],
      [ "Memory Usage", "SimGridSupport.html#SimulationMemoryUsage", null ]
    ] ],
    [ "The StarPU OpenMP Runtime Support (SORS)", "OpenMPRuntimeSupport.html", [
      [ "Implementation Details and Specificities", "OpenMPRuntimeSupport.html#OMPImplementation", [
        [ "Main Thread", "OpenMPRuntimeSupport.html#OMPMainThread", null ],
        [ "Extended Task Semantics", "OpenMPRuntimeSupport.html#OMPTaskSemantics", null ]
      ] ],
      [ "Configuration", "OpenMPRuntimeSupport.html#OMPConfiguration", null ],
      [ "Initialization and Shutdown", "OpenMPRuntimeSupport.html#OMPInitExit", null ],
      [ "Parallel Regions and Worksharing", "OpenMPRuntimeSupport.html#OMPSharing", [
        [ "Parallel Regions", "OpenMPRuntimeSupport.html#OMPParallel", null ],
        [ "Parallel For", "OpenMPRuntimeSupport.html#OMPFor", null ],
        [ "Sections", "OpenMPRuntimeSupport.html#OMPSections", null ],
        [ "Single", "OpenMPRuntimeSupport.html#OMPSingle", null ]
      ] ],
      [ "Tasks", "OpenMPRuntimeSupport.html#OMPTask", [
        [ "Explicit Tasks", "OpenMPRuntimeSupport.html#OMPTaskExplicit", null ],
        [ "Data Dependencies", "OpenMPRuntimeSupport.html#OMPDataDependencies", null ],
        [ "TaskWait and TaskGroup", "OpenMPRuntimeSupport.html#OMPTaskSyncs", null ]
      ] ],
      [ "Synchronization Support", "OpenMPRuntimeSupport.html#OMPSynchronization", [
        [ "Simple Locks", "OpenMPRuntimeSupport.html#OMPSimpleLock", null ],
        [ "Nestable Locks", "OpenMPRuntimeSupport.html#OMPNestableLock", null ],
        [ "Critical Sections", "OpenMPRuntimeSupport.html#OMPCritical", null ],
        [ "Barriers", "OpenMPRuntimeSupport.html#OMPBarrier", null ]
      ] ]
    ] ],
    [ "Clustering A Machine", "ClusteringAMachine.html", [
      [ "General Ideas", "ClusteringAMachine.html#ClusteringGeneralIdeas", null ],
      [ "Creating Clusters", "ClusteringAMachine.html#CreatingClusters", null ],
      [ "Example Of Constraining OpenMP", "ClusteringAMachine.html#ExampleOfConstrainingOpenMP", null ],
      [ "Creating Custom Clusters", "ClusteringAMachine.html#CreatingCustomClusters", null ],
      [ "Clusters With Scheduling", "ClusteringAMachine.html#ClustersWithSchedulingContextsAPI", null ]
    ] ],
    [ "Interoperability Support", "InteroperabilitySupport.html", [
      [ "StarPU Resource Management", "InteroperabilitySupport.html#ResourceManagement", [
        [ "Linking a program with the starpurm module", "InteroperabilitySupport.html#Build", null ],
        [ "Initialization and Shutdown", "InteroperabilitySupport.html#InitExit", null ],
        [ "Default Context", "InteroperabilitySupport.html#DefCTX", null ],
        [ "Temporary Contexts", "InteroperabilitySupport.html#TmpCTXS", null ]
      ] ]
    ] ],
    [ "Execution Configuration Through Environment Variables", "ExecutionConfigurationThroughEnvironmentVariables.html", [
      [ "Configuring Workers", "ExecutionConfigurationThroughEnvironmentVariables.html#EnvConfiguringWorkers", null ],
      [ "Configuring The Scheduling Engine", "ExecutionConfigurationThroughEnvironmentVariables.html#ConfiguringTheSchedulingEngine", null ],
      [ "Extensions", "ExecutionConfigurationThroughEnvironmentVariables.html#Extensions", null ],
      [ "Miscellaneous And Debug", "ExecutionConfigurationThroughEnvironmentVariables.html#MiscellaneousAndDebug", null ],
      [ "Configuring The Hypervisor", "ExecutionConfigurationThroughEnvironmentVariables.html#ConfiguringTheHypervisor", null ]
    ] ],
    [ "Compilation Configuration", "CompilationConfiguration.html", [
      [ "Common Configuration", "CompilationConfiguration.html#CommonConfiguration", null ],
      [ "Configuring Workers", "CompilationConfiguration.html#ConfiguringWorkers", null ],
      [ "Extension Configuration", "CompilationConfiguration.html#ExtensionConfiguration", null ],
      [ "Advanced Configuration", "CompilationConfiguration.html#AdvancedConfiguration", null ]
    ] ],
    [ "Files", "Files.html", null ],
    [ "Full source code for the ’Scaling a Vector’ example", "FullSourceCodeVectorScal.html", [
      [ "Main Application", "FullSourceCodeVectorScal.html#MainApplication", null ],
      [ "CPU Kernel", "FullSourceCodeVectorScal.html#CPUKernel", null ],
      [ "CUDA Kernel", "FullSourceCodeVectorScal.html#CUDAKernel", null ],
      [ "OpenCL Kernel", "FullSourceCodeVectorScal.html#OpenCLKernel", [
        [ "Invoking the Kernel", "FullSourceCodeVectorScal.html#InvokingtheKernel", null ],
        [ "Source of the Kernel", "FullSourceCodeVectorScal.html#SourceoftheKernel", null ]
      ] ]
    ] ],
    [ "The GNU Free Documentation License", "GNUFreeDocumentationLicense.html", [
      [ "ADDENDUM: How to use this License for your documents", "GNUFreeDocumentationLicense.html#ADDENDUM", null ]
    ] ],
    [ "Deprecated List", "deprecated.html", null ],
    [ "Modules", "modules.html", "modules" ],
    [ "Data Structures", "annotated.html", [
      [ "Data Structures", "annotated.html", "annotated_dup" ],
      [ "Data Structure Index", "classes.html", null ],
      [ "Data Fields", "functions.html", [
        [ "All", "functions.html", "functions_dup" ],
        [ "Variables", "functions_vars.html", "functions_vars" ]
      ] ]
    ] ],
    [ "Files", null, [
      [ "File List", "files.html", "files" ],
      [ "Globals", "globals.html", [
        [ "All", "globals.html", "globals_dup" ],
        [ "Functions", "globals_func.html", "globals_func" ],
        [ "Variables", "globals_vars.html", null ],
        [ "Typedefs", "globals_type.html", null ],
        [ "Enumerations", "globals_enum.html", null ],
        [ "Enumerator", "globals_eval.html", null ],
        [ "Macros", "globals_defs.html", "globals_defs" ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
".html",
"OutOfCore.html#OOCWontUse",
"group__API__Codelet__And__Tasks.html#a24e7ec85b5c3c7800676db5c2061a71a",
"group__API__Data__Interfaces.html#a00927819b3899892ec152968efe0b158",
"group__API__Data__Interfaces.html#ga7b1f8a896527eb5d667b3e6ccf0ce7bb",
"group__API__Data__Management.html#ga5458fc0ffdc4b6bae960520f5f599ae5",
"group__API__FxT__Support.html#a027b243e7f06772e3eb78f5ba3f7fed9",
"group__API__Interop__Support.html#ga05da3da2a43ade7e1ebb61662bdf1e21",
"group__API__MPI__Support.html#ga8f53f2dd374cbea544763efed25284cd",
"group__API__Modularized__Scheduler.html#ga752889050651f6e3c83ddd2c3f96c0ff",
"group__API__OpenMP__Runtime__Support.html#ga5790ead92feacb71e3882de730170b05",
"group__API__Performance__Model.html#addc058e80e8075ecb7474da3a3de3885",
"group__API__SC__Hypervisor.html#ga4808bbccd3d39478fae09a4feeaf7d65",
"group__API__Scheduling__Contexts.html#gaa22c292025192dd02849249bb4420c82",
"group__API__Theoretical__Lower__Bound__on__Execution__Time.html#ga99f073d0ad7604366ef3a8f805b5f060",
"group__API__Workers__Properties.html#ga173d616aefe98c33a47a847fd2fca37d",
"interfacefstarpu__mod_1_1fstarpu__data__descr__array__free.html#a1f5e6876e2c161d738c89b65de3f4fd7",
"interfacefstarpu__mod_1_1fstarpu__sched__ctx__list__task__counters__decrement.html#a598cebbcf7a70b1f199330640c9f3e5c",
"interfacefstarpu__mpi__mod_1_1fstarpu__mpi__issend__detached.html#a5c7740cbc344e0a04cd8237f085d6884",
"starpu__data__interfaces_8h.html"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';