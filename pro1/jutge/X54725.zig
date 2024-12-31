const std = @import("std");

fn readInt(allocator: std.mem.Allocator, reader: anytype) !i32 {
    var list = std.ArrayList(u8).init(allocator);
    defer list.deinit();
    while (true) {
        const c = reader.readByte() catch |err| switch (err) {
            error.EndOfStream => break,
            else => return err,
        };
        if (c == ' ' or c == '\n') {
            break;
        }

        try list.append(c);
    }

    const int = try std.fmt.parseInt(i32, list.items, 10);
    return int;
}

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();
    const allocator = std.heap.page_allocator;

    const a = try readInt(allocator, stdin);
    const b = try readInt(allocator, stdin);

    try stdout.print("{}\n", .{@min(a, b)});
}
