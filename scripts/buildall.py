
import os

print('Building project...')

# Determine the build directory path
build_dir = os.path.abspath('../build')

# Create the build directory if it does not exist
if not os.path.exists(build_dir):
    os.makedirs(build_dir)

# Change to the build directory
os.chdir(build_dir)

# Compile the client and server programs
# Note: Adjust the list of source files as necessary
client_sources = [
    '../src/connection/Client.cpp',
    '../src/connection/Network.cpp',
    '../src/common/Util.cpp',
    '../src/gameboard/GameBoard.cpp',
    '../src/io/IO.cpp',
    '../src/gamepieces/Bishop.cpp',
    '../src/gamepieces/Empty.cpp',
    '../src/gamepieces/King.cpp',
    '../src/gamepieces/Knight.cpp',
    '../src/gamepieces/Pawn.cpp',
    '../src/gamepieces/Queen.cpp',
    '../src/gamepieces/Rook.cpp',
    "../src/connection/MessageProtocol.cpp"
]

server_sources = [
    '../src/connection/Server.cpp',
    '../src/connection/Network.cpp',
    '../src/common/Util.cpp',
    '../src/gameboard/GameBoard.cpp',
    '../src/io/IO.cpp',
    '../src/gamepieces/Bishop.cpp',
    '../src/gamepieces/Empty.cpp',
    '../src/gamepieces/King.cpp',
    '../src/gamepieces/Knight.cpp',
    '../src/gamepieces/Pawn.cpp',
    '../src/gamepieces/Queen.cpp',
    '../src/gamepieces/Rook.cpp',
    "../src/connection/MessageProtocol.cpp"
]

# Define compile command
def compile_program(sources, output_name):
    command = [
        'g++',
        '-g',  # Debugging information
        '-std=c++11',  # C++ standard
        '-o', output_name,
        *sources,  # List of source files
        '-lws2_32'  # Link against the Windows Sockets library
    ]
    
    print(f"Compiling {output_name}...")
    os.system(' '.join(command))
    print(f"Compilation of {output_name} completed.")

# Compile the client and server
compile_program(client_sources, 'client')
compile_program(server_sources, 'server')

print('Build complete')

