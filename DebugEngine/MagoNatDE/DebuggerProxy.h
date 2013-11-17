/*
   Copyright (c) 2010 Aldo J. Nunez

   Licensed under the Apache License, Version 2.0.
   See the LICENSE text file for details.
*/

#pragma once

#include "..\Exec\DebuggerProxy.h"


namespace Mago
{
    class ArchData;
    class IRegisterSet;


    class DebuggerProxy
    {
        MagoCore::DebuggerProxy mExecThread;
        RefPtr<ArchData>    mArch;

    public:
        DebuggerProxy();
        ~DebuggerProxy();

        HRESULT Init( IEventCallback* callback );
        HRESULT Start();
        void    Shutdown();

        HRESULT GetSystemInfo( IProcess* process, ArchData*& sysInfo );

        HRESULT Launch( LaunchInfo* launchInfo, IProcess*& process );
        HRESULT Attach( uint32_t id, IProcess*& process );

        HRESULT Terminate( IProcess* process );
        HRESULT Detach( IProcess* process );

        HRESULT ResumeLaunchedProcess( IProcess* process );

        HRESULT ReadMemory( 
            IProcess* process, 
            Address address,
            SIZE_T length, 
            SIZE_T& lengthRead, 
            SIZE_T& lengthUnreadable, 
            uint8_t* buffer );

        HRESULT WriteMemory( 
            IProcess* process, 
            Address address,
            SIZE_T length, 
            SIZE_T& lengthWritten, 
            uint8_t* buffer );

        HRESULT SetBreakpoint( IProcess* process, Address address );
        HRESULT RemoveBreakpoint( IProcess* process, Address address );

        HRESULT StepOut( IProcess* process, Address targetAddr, bool handleException );
        HRESULT StepInstruction( IProcess* process, bool stepIn, bool handleException );
        HRESULT StepRange( IProcess* process, bool stepIn, AddressRange range, bool handleException );

        HRESULT Continue( IProcess* process, bool handleException );
        HRESULT Execute( IProcess* process, bool handleException );

        HRESULT AsyncBreak( IProcess* process );

        HRESULT GetThreadContext( IProcess* process, ::Thread* thread, IRegisterSet*& regSet );
        HRESULT SetThreadContext( IProcess* process, ::Thread* thread, IRegisterSet* regSet );

    private:
        HRESULT CacheSystemInfo();
    };
}
