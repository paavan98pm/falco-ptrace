/*

Copyright (c) 2013-2018 Draios Inc. dba Sysdig.

This file is dual licensed under either the MIT or GPL 2. See MIT.txt
or GPL2.txt for full copies of the license.

*/
#include "ppm_events_public.h"

#ifdef __KERNEL__
#include "ppm.h"
#else
#ifndef UDIG
#define CAPTURE_CONTEXT_SWITCHES
#define CAPTURE_SIGNAL_DELIVERIES
#define CAPTURE_PAGE_FAULTS
#endif /* UDIG */
#endif /* __KERNEL__ */

#if defined(__KERNEL__) || defined(UDIG)
#define FILLER_REF(x) f_##x, PPM_FILLER_##x
#else
#define FILLER_REF(x) 0, PPM_FILLER_##x
#endif /* __KERNEL__ */

#define f_sys_socket_x f_sys_single_x

const struct ppm_event_entry g_ppm_events[PPM_EVENT_MAX] = {
	[PPME_GENERIC_E] = {FILLER_REF(sys_generic)},
	[PPME_GENERIC_X] = {FILLER_REF(sys_generic)},
	[PPME_SYSCALL_OPEN_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_OPEN_X] = {FILLER_REF(sys_open_x)},
	[PPME_SYSCALL_CLOSE_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_CLOSE_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_READ_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {2} } },
	[PPME_SYSCALL_READ_X] = {FILLER_REF(sys_read_x)},
	[PPME_SYSCALL_WRITE_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {2} } },
	[PPME_SYSCALL_WRITE_X] = {FILLER_REF(sys_write_x)},
	[PPME_PROCEXIT_1_E] = {FILLER_REF(sys_procexit_e)},
	[PPME_SOCKET_SOCKET_E] = {FILLER_REF(sys_autofill), 3, APT_SOCK, {{0}, {1}, {2} } },
	[PPME_SOCKET_SOCKET_X] = {FILLER_REF(sys_socket_x)},
	[PPME_SOCKET_BIND_E] = {FILLER_REF(sys_autofill), 1, APT_SOCK, {{0} } },
	[PPME_SOCKET_BIND_X] = {FILLER_REF(sys_socket_bind_x)},
	[PPME_SOCKET_CONNECT_E] = {FILLER_REF(sys_autofill), 1, APT_SOCK, {{0} } },
	[PPME_SOCKET_CONNECT_X] = {FILLER_REF(sys_connect_x)},
	[PPME_SOCKET_LISTEN_E] = {FILLER_REF(sys_autofill), 2, APT_SOCK, {{0}, {1} } },
	[PPME_SOCKET_LISTEN_X] = {FILLER_REF(sys_single_x)},
	[PPME_SOCKET_SEND_E] = {FILLER_REF(sys_send_e)},
	[PPME_SOCKET_SEND_X] = {FILLER_REF(sys_send_x)},
	[PPME_SOCKET_SENDTO_E] = {FILLER_REF(sys_sendto_e)},
	[PPME_SOCKET_SENDTO_X] = {FILLER_REF(sys_send_x)},
	[PPME_SOCKET_RECV_E] = {FILLER_REF(sys_autofill), 2, APT_SOCK, {{0}, {2} } },
	[PPME_SOCKET_RECV_X] = {FILLER_REF(sys_recv_x)},
	[PPME_SOCKET_RECVFROM_E] = {FILLER_REF(sys_autofill), 2, APT_SOCK, {{0}, {2} } },
	[PPME_SOCKET_RECVFROM_X] = {FILLER_REF(sys_recvfrom_x)},
#ifndef WDIG
	[PPME_SOCKET_SHUTDOWN_E] = {FILLER_REF(sys_shutdown_e)},
	[PPME_SOCKET_SHUTDOWN_X] = {FILLER_REF(sys_single_x)},
#endif
	[PPME_SOCKET_GETSOCKNAME_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_GETSOCKNAME_X] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_GETPEERNAME_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_GETPEERNAME_X] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_SOCKETPAIR_E] = {FILLER_REF(sys_autofill), 3, APT_SOCK, {{0}, {1}, {2} } },
	[PPME_SOCKET_SOCKETPAIR_X] = {FILLER_REF(sys_socketpair_x)},
	[PPME_SOCKET_SETSOCKOPT_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_SETSOCKOPT_X] = {FILLER_REF(sys_setsockopt_x)},
	[PPME_SOCKET_GETSOCKOPT_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_GETSOCKOPT_X] = {FILLER_REF(sys_getsockopt_x)},
#ifndef WDIG
	[PPME_SOCKET_SENDMSG_E] = {FILLER_REF(sys_sendmsg_e)},
	[PPME_SOCKET_SENDMSG_X] = {FILLER_REF(sys_sendmsg_x)},
	[PPME_SOCKET_SENDMMSG_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_SENDMMSG_X] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_RECVMSG_E] = {FILLER_REF(sys_autofill), 1, APT_SOCK, {{0} } },
	[PPME_SOCKET_RECVMSG_X] = {FILLER_REF(sys_recvmsg_x)},
	[PPME_SOCKET_RECVMMSG_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_RECVMMSG_X] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_CREAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_CREAT_X] = {FILLER_REF(sys_creat_x)},
	[PPME_SYSCALL_PIPE_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_PIPE_X] = {FILLER_REF(sys_pipe_x)},
	[PPME_SYSCALL_EVENTFD_E] = {FILLER_REF(sys_eventfd_e)},
	[PPME_SYSCALL_EVENTFD_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_FUTEX_E] = {FILLER_REF(sys_futex_e)},
	[PPME_SYSCALL_FUTEX_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_STAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_STAT_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_LSTAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_LSTAT_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_FSTAT_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_FSTAT_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_STAT64_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_STAT64_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_LSTAT64_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_LSTAT64_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_FSTAT64_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_FSTAT64_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_EPOLLWAIT_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{2} } },
	[PPME_SYSCALL_EPOLLWAIT_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_POLL_E] = {FILLER_REF(sys_poll_e)},
	[PPME_SYSCALL_POLL_X] = {FILLER_REF(sys_poll_x)},
	[PPME_SYSCALL_SELECT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_SELECT_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_NEWSELECT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_NEWSELECT_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_LSEEK_E] = {FILLER_REF(sys_lseek_e)},
	[PPME_SYSCALL_LSEEK_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_LLSEEK_E] = {FILLER_REF(sys_llseek_e)},
	[PPME_SYSCALL_LLSEEK_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_GETCWD_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETCWD_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_CHDIR_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_CHDIR_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_FCHDIR_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_FCHDIR_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_UNLINK_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_UNLINK_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_UNLINKAT_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {1} } },
	[PPME_SYSCALL_UNLINKAT_X] = {FILLER_REF(sys_single_x)},
#ifdef _64BIT_ARGS_SINGLE_REGISTER
	[PPME_SYSCALL_PREAD_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {2}, {3} } },
#else
	[PPME_SYSCALL_PREAD_E] = {FILLER_REF(sys_pread64_e)},
#endif
	[PPME_SYSCALL_PREAD_X] = {FILLER_REF(sys_read_x)},
#ifdef _64BIT_ARGS_SINGLE_REGISTER
	[PPME_SYSCALL_PWRITE_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {2}, {3} } },
#else
	[PPME_SYSCALL_PWRITE_E] = {FILLER_REF(sys_pwrite64_e)},
 #endif
	[PPME_SYSCALL_PWRITE_X] = {FILLER_REF(sys_write_x)},
	[PPME_SYSCALL_READV_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_READV_X] = {FILLER_REF(sys_readv_preadv_x)},
	[PPME_SYSCALL_WRITEV_E] = {FILLER_REF(sys_writev_e)},
	[PPME_SYSCALL_WRITEV_X] = {FILLER_REF(sys_writev_pwritev_x)},
#ifdef _64BIT_ARGS_SINGLE_REGISTER
	[PPME_SYSCALL_PREADV_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {3} } },
#else
	[PPME_SYSCALL_PREADV_E] = {FILLER_REF(sys_preadv64_e)},
#endif
	[PPME_SYSCALL_PREADV_X] = {FILLER_REF(sys_readv_preadv_x)},
	[PPME_SYSCALL_PWRITEV_E] = {FILLER_REF(sys_pwritev_e)},
	[PPME_SYSCALL_PWRITEV_X] = {FILLER_REF(sys_writev_pwritev_x)},
	[PPME_SYSCALL_DUP_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{0} } },
	[PPME_SYSCALL_DUP_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_SIGNALFD_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {AF_ID_USEDEFAULT, 0}, {AF_ID_USEDEFAULT, 0} } },
	[PPME_SYSCALL_SIGNALFD_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_KILL_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {1} } },
	[PPME_SYSCALL_KILL_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_TKILL_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {1} } },
	[PPME_SYSCALL_TKILL_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_TGKILL_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {1}, {2} } },
	[PPME_SYSCALL_TGKILL_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_NANOSLEEP_E] = {FILLER_REF(sys_nanosleep_e)},
	[PPME_SYSCALL_NANOSLEEP_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_TIMERFD_CREATE_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_USEDEFAULT, 0}, {AF_ID_USEDEFAULT, 0} } },
	[PPME_SYSCALL_TIMERFD_CREATE_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_INOTIFY_INIT_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_USEDEFAULT, 0} } },
	[PPME_SYSCALL_INOTIFY_INIT_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_GETRLIMIT_E] = {FILLER_REF(sys_getrlimit_setrlimit_e)},
	[PPME_SYSCALL_GETRLIMIT_X] = {FILLER_REF(sys_getrlimit_setrlrimit_x)},
	[PPME_SYSCALL_SETRLIMIT_E] = {FILLER_REF(sys_getrlimit_setrlimit_e)},
	[PPME_SYSCALL_SETRLIMIT_X] = {FILLER_REF(sys_getrlimit_setrlrimit_x)},
	[PPME_SYSCALL_PRLIMIT_E] = {FILLER_REF(sys_prlimit_e)},
	[PPME_SYSCALL_PRLIMIT_X] = {FILLER_REF(sys_prlimit_x)},
	[PPME_DROP_E] = {FILLER_REF(sched_drop)},
	[PPME_DROP_X] = {FILLER_REF(sched_drop)},
	[PPME_SYSCALL_FCNTL_E] = {FILLER_REF(sys_fcntl_e)},
	[PPME_SYSCALL_FCNTL_X] = {FILLER_REF(sys_single_x)},
#ifdef CAPTURE_CONTEXT_SWITCHES
	[PPME_SCHEDSWITCH_6_E] = {FILLER_REF(sched_switch_e)},
#endif
	[PPME_SYSCALL_BRK_4_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{0} } },
	[PPME_SYSCALL_BRK_4_X] = {FILLER_REF(sys_brk_munmap_mmap_x)},
	[PPME_SYSCALL_MMAP_E] = {FILLER_REF(sys_mmap_e)},
	[PPME_SYSCALL_MMAP_X] = {FILLER_REF(sys_brk_munmap_mmap_x)},
	[PPME_SYSCALL_MMAP2_E] = {FILLER_REF(sys_mmap_e)},
	[PPME_SYSCALL_MMAP2_X] = {FILLER_REF(sys_brk_munmap_mmap_x)},
	[PPME_SYSCALL_MUNMAP_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {1} } },
	[PPME_SYSCALL_MUNMAP_X] = {FILLER_REF(sys_brk_munmap_mmap_x)},
	[PPME_SYSCALL_SPLICE_E] = {FILLER_REF(sys_autofill), 4, APT_REG, {{0}, {2}, {4}, {5} } },
	[PPME_SYSCALL_SPLICE_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_PTRACE_E] = {FILLER_REF(sys_ptrace_e)},
	[PPME_SYSCALL_PTRACE_X] = {FILLER_REF(sys_ptrace_x)},
	[PPME_SYSCALL_IOCTL_3_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {1}, {2} } },
	[PPME_SYSCALL_IOCTL_3_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_RENAME_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_RENAME_X] = {FILLER_REF(sys_autofill), 3, APT_REG, {{AF_ID_RETVAL}, {0}, {1} } },
	[PPME_SYSCALL_RENAMEAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_RENAMEAT_X] = {FILLER_REF(sys_renameat_x)},
	[PPME_SYSCALL_SYMLINK_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_SYMLINK_X] = {FILLER_REF(sys_autofill), 3, APT_REG, {{AF_ID_RETVAL}, {0}, {1} } },
	[PPME_SYSCALL_SYMLINKAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_SYMLINKAT_X] = {FILLER_REF(sys_symlinkat_x)},
	[PPME_SYSCALL_SENDFILE_E] = {FILLER_REF(sys_sendfile_e)},
	[PPME_SYSCALL_SENDFILE_X] = {FILLER_REF(sys_sendfile_x)},
	[PPME_SYSCALL_QUOTACTL_E] = {FILLER_REF(sys_quotactl_e)},
	[PPME_SYSCALL_QUOTACTL_X] = {FILLER_REF(sys_quotactl_x)},
	[PPME_SYSCALL_SETRESUID_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {1}, {2} } },
	[PPME_SYSCALL_SETRESUID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_SETRESGID_E] = {FILLER_REF(sys_autofill), 3, APT_REG, {{0}, {1}, {2} } },
	[PPME_SYSCALL_SETRESGID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSDIGEVENT_E] = {FILLER_REF(sys_sysdigevent_e)},
	[PPME_SYSCALL_SETUID_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{0} } },
	[PPME_SYSCALL_SETUID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_SETGID_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{0} } },
	[PPME_SYSCALL_SETGID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_GETUID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETUID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_GETEUID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETEUID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_GETGID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETGID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_GETEGID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETEGID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_GETRESUID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETRESUID_X] = {FILLER_REF(sys_getresuid_and_gid_x)},
	[PPME_SYSCALL_GETRESGID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_GETRESGID_X] = {FILLER_REF(sys_getresuid_and_gid_x)},
	[PPME_SYSCALL_CLONE_20_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_CLONE_20_X] = {FILLER_REF(proc_startupdate)},
	[PPME_SYSCALL_FORK_20_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_FORK_20_X] = {FILLER_REF(proc_startupdate)},
	[PPME_SYSCALL_VFORK_20_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_VFORK_20_X] = {FILLER_REF(proc_startupdate)},
 #ifdef CAPTURE_SIGNAL_DELIVERIES
	[PPME_SIGNALDELIVER_E] = {FILLER_REF(sys_signaldeliver_e)},
	[PPME_SIGNALDELIVER_X] = {FILLER_REF(sys_empty)},
 #endif
	[PPME_SYSCALL_GETDENTS_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_GETDENTS_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_GETDENTS64_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_GETDENTS64_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_SETNS_E] = {FILLER_REF(sys_setns_e)},
	[PPME_SYSCALL_SETNS_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_FLOCK_E] = {FILLER_REF(sys_flock_e)},
	[PPME_SYSCALL_FLOCK_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_CPU_HOTPLUG_E] = {FILLER_REF(cpu_hotplug_e)},
	[PPME_SOCKET_ACCEPT_5_E] = {FILLER_REF(sys_empty)},
	[PPME_SOCKET_ACCEPT_5_X] = {FILLER_REF(sys_accept_x)},
	[PPME_SOCKET_ACCEPT4_5_E] = {FILLER_REF(sys_accept4_e)},
	[PPME_SOCKET_ACCEPT4_5_X] = {FILLER_REF(sys_accept_x)},
	[PPME_SYSCALL_SEMOP_E] = {FILLER_REF(sys_single)},
	[PPME_SYSCALL_SEMOP_X] = {FILLER_REF(sys_semop_x)},
	[PPME_SYSCALL_SEMCTL_E] = {FILLER_REF(sys_semctl_e)},
	[PPME_SYSCALL_SEMCTL_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_PPOLL_E] = {FILLER_REF(sys_ppoll_e)},
	[PPME_SYSCALL_PPOLL_X] = {FILLER_REF(sys_poll_x)}, /* exit same for poll() and ppoll() */
	[PPME_SYSCALL_MOUNT_E] = {FILLER_REF(sys_mount_e)},
	[PPME_SYSCALL_MOUNT_X] = {FILLER_REF(sys_autofill), 4, APT_REG, {{AF_ID_RETVAL}, {0}, {1}, {2} } },
	[PPME_SYSCALL_UMOUNT_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{1} } },
	[PPME_SYSCALL_UMOUNT_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_SEMGET_E] = {FILLER_REF(sys_semget_e)},
	[PPME_SYSCALL_SEMGET_X] = {FILLER_REF(sys_single_x)},
	[PPME_SYSCALL_ACCESS_E] = {FILLER_REF(sys_access_e)},
	[PPME_SYSCALL_ACCESS_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_CHROOT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_CHROOT_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_SETSID_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_SETSID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_SETPGID_E] = {FILLER_REF(sys_autofill), 2, APT_REG, {{0}, {1} } },
	[PPME_SYSCALL_SETPGID_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_MKDIR_2_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_USEDEFAULT, 0} } },
	[PPME_SYSCALL_MKDIR_2_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_RMDIR_2_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_RMDIR_2_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_UNSHARE_E] = {FILLER_REF(sys_unshare_e)},
	[PPME_SYSCALL_UNSHARE_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_EXECVE_19_E] = {FILLER_REF(sys_execve_e)},
	[PPME_SYSCALL_EXECVE_19_X] = {FILLER_REF(proc_startupdate)},
 #ifdef CAPTURE_PAGE_FAULTS
	[PPME_PAGE_FAULT_E] = {FILLER_REF(sys_pagefault_e)},
	[PPME_PAGE_FAULT_X] = {FILLER_REF(sys_empty)},
 #endif
	[PPME_SYSCALL_BPF_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{0} } },
	[PPME_SYSCALL_BPF_X] = {FILLER_REF(sys_bpf_x)},
	[PPME_SYSCALL_SECCOMP_E] = {FILLER_REF(sys_autofill), 1, APT_REG, {{0}, {1} } },
	[PPME_SYSCALL_SECCOMP_X] = {FILLER_REF(sys_autofill), 1, APT_REG, {{AF_ID_RETVAL} } },
	[PPME_SYSCALL_UNLINK_2_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_UNLINK_2_X] = {FILLER_REF(sys_autofill), 2, APT_REG, {{AF_ID_RETVAL}, {0} } },
	[PPME_SYSCALL_UNLINKAT_2_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_UNLINKAT_2_X] = {FILLER_REF(sys_unlinkat_x)},
	[PPME_SYSCALL_MKDIRAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_MKDIRAT_X] = {FILLER_REF(sys_mkdirat_x)},
	[PPME_SYSCALL_OPENAT_2_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_OPENAT_2_X] = {FILLER_REF(sys_openat_x)},
	[PPME_SYSCALL_LINK_2_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_LINK_2_X] = {FILLER_REF(sys_autofill), 3, APT_REG, {{AF_ID_RETVAL}, {0}, {1} } },
	[PPME_SYSCALL_LINKAT_2_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_LINKAT_2_X] = {FILLER_REF(sys_linkat_x)},
	[PPME_SYSCALL_FCHMODAT_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_FCHMODAT_X] = {FILLER_REF(sys_fchmodat_x)},
	[PPME_SYSCALL_CHMOD_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_CHMOD_X] = {FILLER_REF(sys_chmod_x)},
	[PPME_SYSCALL_FCHMOD_E] = {FILLER_REF(sys_empty)},
	[PPME_SYSCALL_FCHMOD_X] = {FILLER_REF(sys_fchmod_x)}
#endif /* WDIG */
};