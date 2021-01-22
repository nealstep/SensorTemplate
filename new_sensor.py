#!/usr/bin/env python3
#

from os import mkdir, rename
from os.path import dirname, realpath, exists, join as pjoin
from sys import argv

FLAG = "// {} end flag"
PATH = dirname(realpath(__file__))
FORCE = True

BASE_H = "// #define S_{}\n"
SENSOR_H = '''
#ifdef S_{}
#include <s_{}.h>
#endif // S_{}
'''

SENSOR_CPP_1 = '''
#ifdef S_{}
    s_{}_init();
#endif // S_{}
'''

SENSOR_CPP_2 = '''
#ifdef S_{}
    s_{}_check();
#endif // S_{}
'''

if len(argv) != 2:
    print ("Usage: {} SENSOR".format(argv[0]))
    exit(1)

name = {
    'upper': argv[1].upper(),
    'lower': argv[1].lower(),
    'upper_s': "S_{}".format(argv[1].upper()),
    'lower_s': "s_{}".format(argv[1].lower()),
}

def add_before(fn, flag, txt, flag2=None, txt2=None):
    fnn = fn + ".new"
    fno = fn + ".old"
    if not exists(fn):
        print("Exiting original file does not exist ({})".format(fn))
        exit(1)
    if exists(fnn) and not FORCE:
        print("Exiting new file exists ({})".format(fnn))
        exit(1)
    with open(fn) as fpr:
        with open(fnn, 'w') as fpw:
            for line in fpr:
                if line.strip() == flag:
                    fpw.write(txt)
                if flag2:
                    if line.strip() == flag2:
                        fpw.write(txt2)
                fpw.write(line)
    rename(fn, fno)
    rename(fnn, fn)
    
def clone(fs, fd, name):
    if not exists(fs):
        print("Exiting original file does not exist ({})".format(fs))
        exit(1)
    if exists(fd) and not FORCE:
        print("Exiting new file exists ({})".format(fd))
        exit(1)
    with open(fs) as fpr:
        with open(fd, "w") as fpw:
            for line in fpr:
                l1 = line.replace('PROT', name['upper'])
                l2 = l1.replace('prot', name['lower'])
                fpw.write(l2)

def update_base_h(name):
    txt = BASE_H.format(name['upper'])
    flag = FLAG.format("define")
    fn = pjoin(PATH, "lib/common/base.h")
    add_before(fn, flag, txt)

def update_sensors_h(name):
    fn = pjoin(PATH, "lib/sensors/sensors.h")
    flag = FLAG.format("include")
    txt = SENSOR_H.format(name['upper'], name['lower'], name['upper'])
    add_before(fn, flag, txt)

def update_sensors_cpp(name):
    fn = pjoin(PATH, "lib/sensors/sensors.cpp")
    flag = FLAG.format("init")
    txt = SENSOR_CPP_1.format(name['upper'], name['lower'], name['upper'])
    flag2 = FLAG.format("check")
    txt2 = SENSOR_CPP_2.format(name['upper'], name['lower'], name['upper'])
    add_before(fn, flag, txt, flag2, txt2)

def create_dir(name):
    fp = pjoin(PATH, "lib", name['lower_s'])
    if exists(fp) and not FORCE:
        print("Directory already exists ({})".format(fp))
        exit(1)
    mkdir(fp)

def clone_s_prot_h(name):
    fs = pjoin(PATH, "lib/s_prot/s_prot.h")
    fd = pjoin(PATH, "lib", name['lower_s'], "{}.h".format(name['lower_s']))
    clone(fs, fd, name)

def clone_s_prot_cpp(name):
    fs = pjoin(PATH, "lib/s_prot/s_prot.cpp")
    fd = pjoin(PATH, "lib", name['lower_s'], "{}.cpp".format(name['lower_s']))
    clone(fs, fd, name)

print(name)
update_base_h(name)
update_sensors_h(name)
update_sensors_cpp(name)
create_dir(name)
clone_s_prot_h(name)
clone_s_prot_cpp(name)
