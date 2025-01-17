def get_update_bmi_query(username, weight, height):
    
    bmi = weight / (height * height)

    query = f"UPDATE users SET bmi = {bmi} WHERE username = '{username}'"

    print(query)
