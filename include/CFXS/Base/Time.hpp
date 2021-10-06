// [CFXS] //

namespace CFXS {

    using Time_t = uint64_t;

    namespace Time {
        extern volatile Time_t ms;
        extern volatile Time_t cycles;
    }; // namespace Time

} // namespace CFXS