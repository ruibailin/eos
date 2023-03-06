EOS(Embedded OS )
The idea comes from the old rblos which was developped in 1996. 

The new EOS also has more better modulization than the old one and can support 5 types of process:

1.Message-driven process which will be scheduled according to message
2.Time-slot process which is scheduled by time slot.this feature can be added in the future according to requirement
3.Real time process which will be scheduled in every main loop.
4.Routine process which will be called every 1 ms or 10 ms
5.Idle process which will be called when there is no 1,2,4 process called in every main loop

The new EOS has more presice timer and doesn't accumulate time error.