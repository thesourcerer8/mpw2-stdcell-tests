# number of IO in the configuration stream for each chain
NUM_IO = 19

# defines these values for IO configurations
C_MGMT_OUT = 0
C_MGMT_IN = 1
C_USER_BIDIR = 2
C_DISABLE = 3
C_ALL_ONES = 4
C_USER_BIDIR_WPU = 5
C_USER_BIDIR_WPD = 6
C_USER_IN_NOPULL = 7
C_USER_OUT = 8

config_h = [
    C_USER_OUT,  #37
    C_USER_BIDIR_WPU,  #36
    C_USER_BIDIR_WPU,  #35
    C_USER_OUT,  #34
    C_USER_BIDIR_WPU,  #33
    C_USER_BIDIR_WPU,  #32
    C_USER_BIDIR_WPU,  #31
    C_USER_OUT,  #30
    C_USER_BIDIR_WPU,  #29
    C_USER_OUT,  #28
    C_USER_BIDIR_WPU,  #27
    C_USER_OUT,  #26
    C_USER_BIDIR_WPU,  #25
    C_USER_OUT,  #24
    C_USER_BIDIR_WPU,  #23
    C_USER_OUT,  #22
    C_USER_BIDIR_WPU,  #21
    C_USER_OUT,  #20
    C_USER_BIDIR_WPU,  #19
]

del config_h[NUM_IO:]

config_l = [
    C_USER_BIDIR_WPU,   #0
    C_USER_BIDIR_WPU,   #1
    C_USER_OUT,   #2
    C_USER_BIDIR_WPU,   #3
    C_USER_BIDIR_WPU,   #4
    C_USER_OUT,   #5
    C_USER_BIDIR_WPU,   #6
    C_USER_BIDIR_WPU,   #7
    C_USER_BIDIR_WPU,   #8
    C_USER_OUT,   #9
    C_USER_BIDIR_WPU,   #10
    C_USER_BIDIR_WPU,   #11
    C_USER_BIDIR_WPU,   #12
    C_USER_BIDIR_WPU,   #13
    C_USER_OUT,   #14
    C_USER_BIDIR_WPU,   #15
    C_USER_OUT,   #16
    C_USER_BIDIR_WPU,   #17
    C_USER_OUT,   #18
]

del config_l[NUM_IO:]
