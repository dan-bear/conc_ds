/**
 * Raid1:
 * raid1 is a technique known as mirroring, the data is
 * stored in two or more disks and read from an available
 * disk.
 *
 * The devices' page size is 4KB and the read/writes are
 * done to 4KB aligned offsets. The device interface is:
 * void Disk::read(uint64_t offset, void* pBufferOut);
 * void Disk::write(uint64_t offset, void* pBuffer);
 * uint64_t Disk::allocatePage()
 * The offsets are assumed to be 4KB aligned.
 * when calling allocatePage() a 4KB aligned offset is
 * returned.
 *
 * We want to implement a Raid1 controller which provides
 * 3KB read, write and page allocation methods using two
 * Disks (that provides the previously described interface).
 * (see the class defintion and documentation)
 *
 */

#include <cstdint>
class Disk
{
  public:
    void read(uint64_t offset, void* pBufferOut);
    void write(uint64_t offset, void* pBuffer);
    uint64_t allocatePage();
};

class Raid13KBCtrl
{
  public:
    /**
     * Reads data from 3KB aligned offset to 3KB buffer.
     * @param offset 3KB aligned offset.
     * @param pBufferOut a 3KB buffer to write the data too.
     */
    void read(uint64_t offset, void* pBufferOut){}

    /**
     * Writes data stored in 3KB buffer to 3KB aligned 
     * offset.
     * @param offset 3KB aligned offset.
     * @param pBuffer a 3KB buffer with data to write to the
     * disk.
     */
    void write(uint64_t offset, void* pBuffer){}

    /**
     * Allocated a 3KB page on disk.
     * @return a 3KB aligned offset that the application
     * can issue a write to.
     * @note For example, the application can run the next
     * code.
     * void someFunc(){
     *     std::allocator<char> allocator;
     *     char* pBuffer = allocator.allocate(3000);
     *     writeMyDataToBuffer(pBuffer);
     *     uint64_t offset = pRaid3KBCtrl->allocatePage();
     *     pRaid3KBCtrl->write(offset, pBuffer);
     *     allocator.deallocate();
     * }
     */
    uint64_t allocatePage(){}

  private:
    Disk* m_pDisk1;
    Disk* m_pDisk2;
};
