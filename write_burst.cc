/**
 * Write Bursts.
 *
 * A system with a single storage-device experiences
 * write bursts every few minutes. The write burst is at
 * least an order of magnitude above the device capacity,
 * for example 1000 write-IOps while the device can only
 * make 100 IOps.
 *
 * The device provides the next methods:
 * Device::write(uint64_t offset, void* pBuffer);
 * Device::read(uint64_t offset, void* pBufferOut);
 *
 * Qualitative question:
 *
 *   Given the next conditions:
 *   1: The application calls directly to the device's
 *      write() method when it wishes to execute a write.
 *   2: Device IOPS is 100.
 *   3: The application write burst duration is X seconds and
 *      the write rate during the burst is 1000 IOPS.
 *   What's going to be the the latency of the last write
 *   in the burst? In other words how long the application
 *   is going to wait till the last write-io is issued?
 *
 *   Answer:
 *   - In a X second burst, 1000 * X write IO requests are
 *     sent.
 *   - The last request reaches the queue after X seconds
 *     so the device has already completed 100 * X write IO
 *     requests by the time the last request arrived to the
 *     queue.
 *   - Thus the queue length is 1000 * X - 100 * X = 900 * X.
 *   - Since the device completes 100 requests per second,
 *     the last request is about to wait (900 * X) / 100 =
 *     9*X seconds.
 *
 *   Note: If the burst rate is Y IOPS and the device rate
 *         is Z IOPS when Y > Z, the last request is going
 *         to take:
 *         (Y * X - Z * X) / Z = ((Y-Z)/Z) * X.
 *
 *
 * Quantitative Question:
 *   UNDER THE ASSUMPTION THE SYSTEM DOES NOT NEED TO
 *   HANDLE FAILURES. Use the given device methods above to
 *   implement the next methods:
 *   void fastWrite(unint64_t offset, void* pBuffer);
 *   void fastRead(uint64_t offset, void* pBufferOut);
 *   
 *   the methods should eliminate the read and write 
 *   latency during bursts.
 *
 */
