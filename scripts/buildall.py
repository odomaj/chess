import os

print('bulding project...')

if(os.path.exists(os.getcwd() + '/../build')):
    os.chdir('../build')
else:
    os.chdir('../')
    os.system('mkdir build')
    os.chdir('build')

dir = os.getcwd()

# compiles the system with 4 gigabytes of stack space and the debug flag
os.system('g++ -g -Wl,--stack,4294967296 -std=c++11 ../src/ai/heuristic/Heuristic.cpp ../src/ai/common/AiUtil.cpp ../src/ai/minimax/Minimax.cpp ../src/common/Util.cpp ../src/gameboard/GameBoard.cpp ../src/executive/Executive.cpp ../src/gamepieces/Bishop.cpp ../src/gamepieces/Empty.cpp ../src/gamepieces/King.cpp ../src/gamepieces/Knight.cpp ../src/gamepieces/Pawn.cpp ../src/gamepieces/Queen.cpp ../src/gamepieces/Rook.cpp ../src/io/IO.cpp ../src/main.cpp -o main')

print('build complete')