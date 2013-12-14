/*
   Copyright (c) 2013 Aldo J. Nunez

   Licensed under the Apache License, Version 2.0.
   See the LICENSE text file for details.
*/

#pragma once


namespace Mago
{
    enum CoreProcessType
    {
        CoreProcess_Local,
    };


    class ICoreProcess
    {
    public:
        ICoreProcess() { }

        virtual void            AddRef() = 0;
        virtual void            Release() = 0;

        virtual CreateMethod    GetCreateMethod() = 0;
        virtual uint32_t        GetPid() = 0;
        virtual const wchar_t*  GetExePath() = 0;
        virtual Address         GetEntryPoint() = 0;
        virtual uint16_t        GetMachineType() = 0;

        virtual bool            IsStopped() = 0;
        virtual bool            IsDeleted() = 0;
        virtual bool            IsTerminating() = 0;
        virtual bool            ReachedLoaderBp() = 0;

        virtual CoreProcessType GetProcessType() = 0;

    private:
        ICoreProcess( const ICoreProcess& );
        ICoreProcess& operator=( const ICoreProcess& );
    };


    class ICoreThread
    {
    public:
        ICoreThread() { }

        virtual void            AddRef() = 0;
        virtual void            Release() = 0;

        virtual uint32_t        GetTid() = 0;
        virtual Address         GetStartAddr() = 0;
        virtual Address         GetTebBase() = 0;
        virtual CoreProcessType GetProcessType() = 0;

    private:
        ICoreThread( const ICoreThread& );
        ICoreThread& operator=( const ICoreThread& );
    };


    class ICoreModule
    {
    public:
        ICoreModule() { }

        virtual void            AddRef() = 0;
        virtual void            Release() = 0;

        virtual Address         GetImageBase() = 0;
        virtual Address         GetPreferredImageBase() = 0;
        virtual uint32_t        GetSize() = 0;
        virtual uint16_t        GetMachine() = 0;
        virtual const wchar_t*  GetExePath() = 0;

        virtual bool            IsDeleted() = 0;

    private:
        ICoreModule( const ICoreModule& );
        ICoreModule& operator=( const ICoreModule& );
    };
}