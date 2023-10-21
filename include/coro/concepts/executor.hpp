#pragma once

#include "coro/concepts/awaitable.hpp"

#include <concepts>
#include <coroutine>

namespace coro::concepts
{

template<typename type>
concept awaiter_or_awaitable = coro::concepts::awaiter<type> || coro::concepts::awaitable<type>;

template<typename type>
concept executor = requires(type t, std::coroutine_handle<> c)
{
    {
        t.schedule()
        } -> coro::concepts::awaiter_or_awaitable;
    {
        t.yield()
        } -> coro::concepts::awaiter_or_awaitable;
    {
        t.resume(c)
        } -> std::same_as<void>;
};

} // namespace coro::concepts
