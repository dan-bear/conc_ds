/**
 * A socket provider controls N sockets. Each socket can
 * be accessed by one thread at a time.
 *
 * When a thread arrives to the socket provider it invokes:
 *
 * uint64_t SocketProvider::acquireSocket(const set<uint64_t>&
 * socketOptions).
 *
 * The acquire socket method excepts a set of sockets
 * (determined by the thread) and returns the first
 * available socket between the ones appearing in the set.
 * For example, if the user pass {2, 3, 5} as the sockets
 * and all of them are currently being used, the first
 * between them that becomes available will be returned to
 * the user. If more than a single socket is available, one
 * of them will be returned (does not matter which one).
 *
 * After using the socket the thread invokes:
 * void SocketProvider::releaseSocket(uint64_t socket)
 *
 * The method releases the socket and makes it available for
 * other threads.
 *
 * Implement the SocketProvider class.
 *
 */

#include <cstdint>
#include <set>
/** Add more includes here. */
using namespace std;

/**
 * The socket provider class.
 */
class SocketProvider
{
    /**
     * Constructor.
     * @note need to be implemented.
     */
    SocketProvider(uint64_t numOfSockets){};

  public:
    /**
     * Acquire socket.
     * @param socketOption a set of sockets requested by the
     * user.
     * @return the first available socket from the given
     * socket options.
     * @note assume all the sockets in the socket options
     * are in the socketProvider domain (if the socket
     * provider holds N sockets, socketOptions is a sub set
     * of {0,1,...,N - 1}).
     */
    uint64_t acquireSocket(const set<uint64_t>& socketOptions);
    /**
     * Releases a socket.
     * @param socket the socket to release.
     * @note assume that the socket is in the
     * socketProvider's domain (socket in {0,1,..., N-1}
     * when the number of sockets in the provider is N).
     * @note assume the caller actually holds the socket,
     * you don't need to protect the provider from
     * adversary users.
     * @note assume the caller releases a socket
     */
    void releaseSocket(uint64_t socket);

  private:
};