int main(void)
{
    RBT_init_systems();
    RBT_connection con;
    RBT_env_load_remote(&con.remote)
    RBT_connect(&con);

    RBT_command command;
    RBT_command_add(SYSTEM_TYPE, &command, RBT_CMD_PUSH_STACK_STR);
    RBT_command_add(SYSTEM_TYPE, &command, "Hello");
    RBT_command_add(SYSTEM_TYPE, &command, RBT_CMD_PUSH_STACK_STR);
    RBT_command_add(SYSTEM_TYPE, &command, "World");
    RBT_command_add(SYSTEM_TYPE, &command, RBT_SAY);
    RBT_command_add(SYSTEM_TYPE, &command, RBT_SHUTDOWN);

    RBT_send(&con, command);
    RBT_command_free(&command);

    RBT_disconnect(&con);
    RBT_connection_free(&con);

    RBT_close_systems();

    return EXIT_SUCCESS;
}
